// Olsr_gamma.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Olsr.h"
#include <stdexcept>
#include <stdlib.h> //exit, EXIT_FAILURE
#include <string.h>
#include <stdio.h>
#include <time.h>//time_t

#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

namespace OLSR_protocol
{

	void Message_header::setSourceaddr(int addr)
	{
		Source_addr=addr;
	}

	void Message_header::set_Msgtype(int type)
	{
		Message_type=type;
	}

	void Message_header::setOrg_addr(int originator)
	{
		Originator_add=originator;
	}

	int   Message_header::getOriginatorAdd()
	{
		return Originator_add;
	}

	int Message_header::getMType()
	{
		return Message_type;
	}

	/*
	MID_message::MID_message()
	{
		IP_OLSR_interface.reserve(5);
	}
	*/

	HELLO_message::HELLO_message()
	{
		 Willingness=WILL_DEFAULT;		
	}

	void HELLO_message::Neigh_interface_add::setNeightype(int type)
	{
		Neighbor_type=type;
	}

	void HELLO_message::Neigh_interface_add::setLinktype(int type)
	{
		Link_type=type;
	}

	int HELLO_message::Neigh_interface_add::getNeighType()
	{
		return this->Neighbor_type;
	}

	int HELLO_message::Neigh_interface_add::getLinkType()
	{
		return this->Link_type;
	}

	int HELLO_message::Neigh_interface_add::getLink_code()
	{
		this->Link_Code=4*this->getNeighType()+this->getLinkType();
		return this->Link_Code;
	}

	TC_message::TC_message()
	{
	}


	Node::Node()
	{
		Main_addr=0;
		MS_ANSN=0;
		L_set.reserve(30);
		Message_sequence_number=0;
	}

	Node::Node(int main_addr)
	{
		Main_addr=main_addr;
		MS_ANSN=0;
		L_set.reserve(30);
		Message_sequence_number=0;
	}

	
	//generam mesajul HELLO
	HELLO_message*& Node::generate_HELLO()
	{
		hello=new HELLO_message();
		Message_sequence_number++;//incrementam valoarea  lui sequence nr la crearea unui nou mesaj
		hello->set_Msgtype(HELLO_MESSAGE);
		hello->setOrg_addr(Main_addr);
		hello->setSourceaddr(Main_addr);
		hello->Msg_SN=Message_sequence_number;

		int i;
		int nr=0;
		bool go=false;
		for( i=0;i<(int)L_set.size();i++)
			if( L_set[i].L_local_iface_addr==hello->Source_addr )//&& L_set[i].L_time >=(int)time(NULL) )//current time)
			{
				HELLO_message::Neigh_interface_add aux;
				//setare Neighbor Type
				for(int j=0;j<(int)Mpr_set.size();j++)
				{
					if( Mpr_set[j].MPR_main_addr==L_set[i].L_neighbor_iface_addr) //main address corresponding to L_neighbor_iface_addr is in the MPR set
						{
							aux.setNeightype(MPR_NEIGH);
							go=true;
						}
				}

				if(go==false)
					for(int k=0;k<(int)N_set.size();k++)
					{
						if( N_set[k].N_neighbor_main_addr==L_set[i].L_neighbor_iface_addr)////main address corresponding to L_neighbor_iface_addr is in the Neighbor set
							if(N_set[k].N_status==SYM)
								aux.setNeightype(SYM_NEIGH);
								else
									if(N_set[k].N_status==NOT_SYM)
										aux.setNeightype(NOT_NEIGH);
					}

				//setare Link Type
				if(L_set[i].L_SYM_time==1 && L_set[i].L_ASYM_time ==0) //not expired
					aux.setLinktype(SYM_LINK);
					else
						if(L_set[i].L_ASYM_time ==1 && L_set[i].L_SYM_time ==0)
							aux.setLinktype(ASYM_LINK);
							else
								if(L_set[i].L_ASYM_time==0 && L_set[i].L_SYM_time==0)
									aux.setLinktype(LOST_LINK);
				//setare neighbor interface addr
				aux.IP_Neighbor_interface=L_set[i].L_neighbor_iface_addr;
				aux.Link_Code=aux.getLink_code();
				hello->Neighbor_list.push_back(aux);
			}

			//pentru setul de vecini 
				bool out=false;//nu a fost publicata
				for(int j=0;j<(int)L_set.size();j++)
				  {
					HELLO_message::Neigh_interface_add p;
					for(int l=0;l<(int)hello->Neighbor_list.size();l++)
							if(hello->Neighbor_list[l].IP_Neighbor_interface==L_set[j].L_neighbor_iface_addr)
								out=true;//a fost publicata
				
						if(!out) //daca nu a fost publicata, atunci o publicam
						{

							p.IP_Neighbor_interface=L_set[j].L_neighbor_iface_addr;
							p.setLinktype(UNSPEC_LINK);//setam link type
					
							//setam neighbor type
							for(int g=0;g<(int)Mpr_set.size();g++)
								if(Mpr_set[g].MPR_main_addr==L_set[j].L_neighbor_iface_addr)
								{
									p.setNeightype(MPR_NEIGH);
								}
							for(int g=0;g<(int)N_set.size();g++)
							{	
								if(N_set[g].N_neighbor_main_addr==L_set[j].L_neighbor_iface_addr)
									if(N_set[g].N_status==SYM)
										p.setNeightype(SYM_NEIGH);
									else
										if(N_set[g].N_status==NOT_SYM)
											p.setNeightype(NOT_NEIGH);
							}
							p.Link_Code=p.getLink_code();
							hello->Neighbor_list.push_back(p);
						}
				   }
			

	
			return hello; //creare mesaj cu succes
	}

	//procesam mesajul HELLO
	//all links MUST be checked in both directions in order to be considered valid
	void Node::process_HELLO(HELLO_message* msg)
	{
		if(msg->getOriginatorAdd()==Main_addr)
			return;

		//populare Link Set
		int ok=false; //nu exista tuplul 
		int j,h;
		for(int i=0;i<(int)L_set.size();i++)
		{
			if(L_set[i].L_neighbor_iface_addr==msg->getOriginatorAdd() && L_set[i].L_local_iface_addr==Main_addr)
				{
					ok=true;//exista tuplul
					break;
				} 
		}

		if(ok==false) //creare tuplu nou
		{
				Link_Set link;
				link.L_neighbor_iface_addr=msg->getOriginatorAdd();
				link.L_local_iface_addr=Main_addr;//adresa interfetei pe care s-a primit mesajul
			
				for(int t=0;t<(int)N_set.size();t++)
					if(N_set[t].N_neighbor_main_addr==msg->getOriginatorAdd() && N_set[t].N_status==SYM)
						{
							link.L_SYM_time=1; 
							link.L_ASYM_time=0;
							break;
						}
					else
						if(N_set[t].N_neighbor_main_addr==msg->getOriginatorAdd() && N_set[t].N_status==NOT_SYM)
						{
							link.L_SYM_time=0; 
							link.L_ASYM_time=1;
							break;
						}
				link.L_time=(int)time(NULL);
				L_set.push_back(link);
		}

		//verific daca vecinul de  la care am primit mesajul este simetric
			bool sym=false;
			for(int l=0;l<(int)N_set.size();l++)
				if(N_set[l].N_neighbor_main_addr==msg->getOriginatorAdd() && N_set[l].N_status==SYM)
				{
					sym=true;
					break;
				}

		//populare 2-hop Neighbor Set
		if(sym==true)
			for(j=0;j<(int)L_set.size();j++)
			{
				if(L_set[j].L_neighbor_iface_addr==msg->getOriginatorAdd() && L_set[j].L_SYM_time==1 && L_set[j].L_ASYM_time==0) //not expired		
				{
					for(h=0;h<(int)msg->Neighbor_list.size();h++)
					{
						if(msg->Neighbor_list[h].getNeighType()==SYM_NEIGH || msg->Neighbor_list[h].getNeighType()==MPR_NEIGH)
						{	if(msg->Neighbor_list[h].IP_Neighbor_interface!=Main_addr) //daca o gaseste arunca adresa, un nod nu este propriul vecin la distanta de 2 hopuri
							{
								//n-a gasit-o, deci creeaza un nou tuplu daca exista deja se modifica doar N_time
								bool deja=false;
								for(int a=0;a<(int)_2hop_set.size();a++)
									if(_2hop_set[a].N_neighbor_main_addr==msg->getOriginatorAdd()  && _2hop_set[a].N_2hop_addr==msg->Neighbor_list[h].IP_Neighbor_interface)
									{
										deja=true;
										break;
									}

									if(deja==false)
									{
										_2hop_Neighbor_Set el;
										el.N_neighbor_main_addr=msg->getOriginatorAdd();
										//main address of the 2 hop neighbor
										el.N_2hop_addr=msg->Neighbor_list[h].IP_Neighbor_interface;
										el.N_time=(int)time(NULL);
										_2hop_set.push_back(el);
									}
							}
						}
							else
								if(msg->Neighbor_list[h].getNeighType()==NOT_NEIGH)
								{
									for(int l =0;l<(int)_2hop_set.size();l++)
										if(msg->Neighbor_list[h].IP_Neighbor_interface==_2hop_set[l].N_2hop_addr && _2hop_set[l].N_neighbor_main_addr==msg->getOriginatorAdd())
											_2hop_set.erase(_2hop_set.begin()+h-1);						
								}
					}
				}	
			}

		
		//populare MPR Selector set 
			for(h=0;h<(int)msg->Neighbor_list.size();h++)
				{
					if(msg->Neighbor_list[h].getNeighType()==MPR_NEIGH && Main_addr==msg->Neighbor_list[h].IP_Neighbor_interface)//verific daca expeditorul l-a selectat ca MPR
						{
							int res=0;
							for(int k=0;k<(int)MS_set.size();k++)
								if(msg->getOriginatorAdd()==MS_set[k].MS_main_addr)
									res++;//nu exista deja un tuplu cu adresa mesajului
							if(res==0)
							{
								MPR_Selector_Set ms;
								ms.MS_main_addr=msg->getOriginatorAdd();
								ms.MS_time=(int)time(NULL);
								MS_set.push_back(ms);
								MS_ANSN++;  //indica o modificare in set 
							}
							else
							{
								for(int p=0;p<(int)MS_set.size();p++)
									if(msg->getOriginatorAdd()==MS_set[p].MS_main_addr)
										MS_set[p].MS_time=(int)time(NULL);
							}
						
					}
				}
	}


	//generare mesaj TC
	TC_message* Node::generate_TC()
	{
		tc=new TC_message();
		Message_sequence_number++;//incrementam valoarea  lui sequence nr la crearea unui nou mesaj
		tc->set_Msgtype(TC_MESSAGE);
		tc->setOrg_addr(Main_addr);
		tc->setSourceaddr(Main_addr); //adresa interfetei sursa
		tc->Msg_SN=Message_sequence_number;
		tc->ANSN=MS_ANSN;
		for(int i=0;i<(int)MS_set.size();i++)
		{
			tc->AN_Main_Address.push_back(MS_set[i].MS_main_addr);
		}

		return tc;
	}


	//procesare mesaj TC
	void Node::process_TC(TC_message *msg)
	{
		if( msg->getOriginatorAdd()==Main_addr)
			return;

		int result=0,i;
		//1.
		for(i=0;i<(int)N_set.size();i++)
		{
			if(N_set[i].N_neighbor_main_addr==msg->Source_addr &&  N_set[i].N_status==SYM)
				result++;
		}

		if(result>0)
		{//2
			for(i=0;i<(int)T_set.size();i++)
			{
				if(T_set[i].T_last_addr==msg->getOriginatorAdd() && T_set[i].T_seq>msg->ANSN)
					return; //message received out of order, discard message
			}

			//3.
			for(i=0;i<(int)T_set.size();i++)
			{
				if(T_set[i].T_last_addr==msg->getOriginatorAdd() && T_set[i].T_seq<msg->ANSN)
					T_set.erase(T_set.begin()+i-1);
			}

				//4
			
			for(i=0;i<(int)msg->AN_Main_Address.size();i++)
			{
				result=0;
				for(int j=0;j<(int)T_set.size();j++)
					if(T_set[j].T_dest_addr==msg->AN_Main_Address[i] && T_set[j].T_last_addr==msg->getOriginatorAdd())
						{
							T_set[j].T_time=(int)time(NULL);
							result++;
						}
					if(result==0 )//nu s-a gasit, cream o noua intrare in set
						{
							Topology_Set t;
							t.T_dest_addr=msg->AN_Main_Address[i];
							t.T_last_addr=msg->getOriginatorAdd();
							t.T_seq=msg->ANSN;
							t.T_time=(int)time(NULL);
							T_set.push_back(t);
						}
			}
			
		}
		else
			//discard message
			return;
	}


	//creare tabela de rutare
	void Node::Routing_table_creation()
	{
		//1.all the entries from the routing table are removed
		int size=R_table.size();
		int i,j;
		int result=0;
		for(i=0;i<size;i++)
		{
			R_table.erase(R_table.begin());
		}

		//2.Neighbor tuple
		int t=N_set.size();
		for(i=0;i<t;i++)
		{
			if(N_set[i].N_status==SYM)
				for(j=0;j<(int)L_set.size();j++)
				{
					if(N_set[i].N_neighbor_main_addr==L_set[j].L_neighbor_iface_addr)
					{
						bool da=false;
						for (int d=0;d<(int)R_table.size();d++)
							if(R_table[d].R_dest_addr==L_set[j].L_neighbor_iface_addr && R_table[d].R_next_addr==L_set[j].L_neighbor_iface_addr)
							{
								da=true;
								break;
							}

							if(da==false)
							{
								Routing_table rt;
								rt.R_dest_addr=L_set[j].L_neighbor_iface_addr;
								rt.R_next_addr=L_set[j].L_neighbor_iface_addr;
								rt.R_dist=1;
								rt.R_iface_addr=L_set[j].L_local_iface_addr;
								R_table.push_back(rt);
							}
					}
						result=0;
						for(int k=0;k<(int)R_table.size();k++)
						{
							if(R_table[k].R_dest_addr==N_set[i].N_neighbor_main_addr && R_table[k].R_next_addr==N_set[i].N_neighbor_main_addr)
								result++;
						}
						if(result==0 )
						{  
							Routing_table rtr;
							rtr.R_dest_addr=N_set[i].N_neighbor_main_addr;
							rtr.R_next_addr=N_set[i].N_neighbor_main_addr;
							rtr.R_dist=1;
							rtr.R_iface_addr=L_set[j].L_local_iface_addr;
							R_table.push_back(rtr);
						}
					
				 }
		}

		// 2-Hop Neighbor Set
		for(i=0;i<(int)_2hop_set.size();i++)
		{
			for(j=0;j<(int)N_set.size();j++)
			{
				if(_2hop_set[i].N_neighbor_main_addr==N_set[j].N_neighbor_main_addr && N_set[j].N_willingness!=WILL_NEVER )
				{
					Routing_table rtrt;
					rtrt.R_dest_addr=_2hop_set[i].N_2hop_addr;
					
					/*R_next_addr  = the R_next_addr of the entry in the routing table with: R_dest_addr == N_neighbor_main_addr of the 2-hop tuple;*/
					/*R_iface_addr = the R_iface_addr of the entry in the routing table with:  R_dest_addr == N_neighbor_main_addr of the 2-hop tuple;*/
					for(int l=0;l<(int)R_table.size();l++)
					{
						if(R_table[l].R_dest_addr==_2hop_set[i].N_neighbor_main_addr)
							{
								rtrt.R_next_addr=R_table[l].R_next_addr;
								rtrt.R_iface_addr=R_table[l].R_iface_addr;
							}	
					}
					rtrt.R_dist=2;

					bool be=false;
						for (int d=0;d<(int)R_table.size();d++)
							if(R_table[d].R_dest_addr==_2hop_set[i].N_2hop_addr  && R_table[d].R_next_addr==rtrt.R_next_addr)
							{
								be=true;
								break;
							}
							if(be==false)
								{
									R_table.push_back(rtrt);
									break;
								}
				}
			}
		}

		//3.
		int h=2;
		result=0;
		bool res=false;
		bool recorded=false;//nu am inregistrat nimic
		while(h)
		{
			recorded=false;
			for(i=0;i<(int)T_set.size();i++)
			{
				for(j=0;j<(int)R_table.size();j++)
					if(T_set[i].T_dest_addr==R_table[j].R_dest_addr)
						result++;
	
				if(result==0)
				{
						for(j=0;j<(int)R_table.size();j++)
							if(T_set[i].T_last_addr==R_table[j].R_dest_addr && R_table[j].R_dist==h)
							{
								//verfificam daca exista intrarea deja
								for(int k=0;k<(int)R_table.size();k++)
									if(R_table[k].R_dest_addr==T_set[i].T_dest_addr && R_table[k].R_next_addr==R_table[j].R_next_addr)
										{
											res=true;
											break;
										}
									if(res==false)
								 //cream una noua
										{
											Routing_table aux;
											aux.R_dest_addr=T_set[i].T_dest_addr;
											aux.R_next_addr=R_table[j].R_next_addr;
											aux.R_dist=h+1;
											aux.R_iface_addr=R_table[j].R_iface_addr;
											R_table.push_back(aux);
											recorded=true;
										}
							}
				 }
			  }
			  
			 if(recorded==true)
					h++;
				else
					break;
		}

	}

}
