#include<string.h>
#include<stdio.h>
#include<vector>

#include<iostream>
using namespace std;

/*
When the OLSRGAMMA_EXPORTS symbol is defined, the OLSRGAMMA_API symbol will set the __declspec(dllexport) modifier in the member function
declarations in this code. This modifier enables the function to be exported by the DLL so that it can be used by other applications. 
When OLSRGAMMA_EXPORTS is undefined—for example, when the header file is included by an application—OLSRGAMMA_API defines the __declspec(dllimport)
modifier in the member function declarations. This modifier optimizes the import of the function in an application. By default, the New Project
template for a DLL adds PROJECTNAME_EXPORTS to the defined symbols for the DLL project. In this example,OLSRGAMMA _EXPORTS is defined when your
Olsr_gamma project is built. For more information, see dllexport, dllimport.
*/

#ifdef	OLS_RGAMMA_EXPORTS
#define OLSR_GAMMA_API __declspec(dllexport) 
#else
#define OLSR_GAMMA_API __declspec(dllimport) 
#endif


//constante pentru OLSR

//Willingness
#define WILL_NEVER        0
#define WILL_LOW          1
#define WILL_DEFAULT      3
#define WILL_HIGH         6
#define WILL_ALWAYS       7

//Link Types
#define UNSPEC_LINK       0 //no specific information about  the links is given.
#define ASYM_LINK         1 //that the links are asymmetric (i.e., the neighbor interface is "heard").
#define SYM_LINK          2 //that the links are symmetric with the interface.
#define LOST_LINK         3 //the links have been lost

//Neighbor Types
#define NOT_NEIGH         0 //that the nodes are either no longer or  have not yet become symmetric neighbors
#define SYM_NEIGH         1 //the neighbors have at least one symmetrical link with this node.
#define MPR_NEIGH         2 //that the neighbors have at least one symmetrical link AND have been selected as MPR by the sender

//Message Type           
#define HELLO_MESSAGE     1
#define TC_MESSAGE        2
#define MID_MESSAGE       3

//Node status
#define NOT_SYM			  1
#define SYM				  2

namespace  OLSR_protocol  //pentru  IPv4
{
	//aceste clase sunt exportate din Olsr_gamma.dll


	//message header
	class __declspec(dllexport) Message_header
	{
		protected:
			int Message_type; //indica tipul mesajului, ia valori de la 1 la 4
			int Originator_add;//main address a nodului expeditor al mesajului
									//acest camp nu se schimba niciodata in timpul retransmisiilor	
		public:	
			int Source_addr; //se schimba in timpul retransmisiilor
			int Msg_SN;// numar unic de identificare pentru fiecare mesaj venit de la un anumit expeditor 


			void setSourceaddr(int); //seteaza  interfata sursa
			void set_Msgtype(int );
			void setOrg_addr(int);
			int getOriginatorAdd();
			int getMType();
	};
/*
	//mesaje MID

	//fiecare nod trimite periodic un mesaj MID tuturor nodurilor din retea prin mecanismul de inundare MPR
	class MID_message:public Message_header
	{
		public:
			vector<char*> IP_OLSR_interface; //adresa IP=15 caractere, versiunea 4 - IPv4
			MID_message();
	};*/

	//mesaje HELLO
	
	//schimbul periodic de mesaje HELLO foloseste la popularea lui Link Set si a  lui neighborhood information base
	class __declspec(dllexport) HELLO_message:public Message_header
	{
		public:
			int Willingness;/* The willingness of a node may be set to any integer value from 0 to
							7, and specifies how willing a node is to be forwarding traffic on
							behalf of other nodes.  
							By default, a node SHOULD advertise a  willingness of WILL_DEFAULT */

			class Neigh_interface_add
			{
				private:
					int Neighbor_type; //pe 2 biti
					int Link_type; //pe 2 biti
				public:
					int Link_Code; //daca link codes <16 (pe 8 biti), atunci va contine doua campuri a cate 2 biti fiecare: Neighbor_type si  Link_type
					int IP_Neighbor_interface; // The address of a neighbor node

					void setNeightype(int);
					void setLinktype(int);
					int getNeighType();
					int getLinkType();
					int getLink_code();	
			};
			vector<Neigh_interface_add>  Neighbor_list;

			HELLO_message();
	};

	//mesaje TC

	class __declspec(dllexport) TC_message:public Message_header
	{
		public:
			int ANSN; //Advertised Neighbor Sequence Number
					  /*este asociat cu advertised neighbor set-ul, de fiecare data cand un nod detecteaza o schimbare in AN set-ul sau, incrementeaza acest ANSN*/
			vector<int> AN_Main_Address; //the main addresses of the advertised neighbors of the Originator node
			
			TC_message();
	};

	//Seturile din fiecare nod

	//Local Link Information Base
	//contine informatii despre legaturile catre vecini
	//informatia aceasta este folosita atunci cand se declara interfetele vecine in mesajele HELLO
	class __declspec(dllexport) Link_Set
	{
		public:
			int L_local_iface_addr;//adresa interfetei nodului local, un capat al legaturii
			int L_neighbor_iface_addr; //adresa nodului vecin, celalalt capat al legaturii
			//char L_main_neigh_addr[15]; //main address of  the neighbor
			int L_SYM_time; //timpul pana cand legatura este considerata simetrica
			int L_ASYM_time; //timpul pana cand interfata vecina este considerata auzita
			int L_time; //cand expira tupl-ul si trebuie eliminat
						// L_SYM_time si L_ASYM_time expirate, atunci legatura este considerata pierduta
	};

	//Neighborhood Information Base
	//setul de vecini
	class __declspec(dllexport) Neighbor_Set
	{
		public:
			int N_neighbor_main_addr; //main address of a neighbor
			int N_status;//specifica daca nodul este NOT_SYM sau SYM
			int N_willingness; //specifies the node's willingness to carry traffic on behalf of other nodes
	};

	//2-hop tuples descriu legaturile simetrice  dintre vecinii sai si vecinatatea la 2 hop-uri distanta
	//descriu deci, si legaturile MPR care prin definitie sunt simetrice
	class __declspec(dllexport) _2hop_Neighbor_Set
	{
		public:
			int N_neighbor_main_addr; //main address of a neighbor
			int N_2hop_addr; //main address of a 2-hop neighbor with a symmetric link to N_neighbor_main_addr
			int N_time; //cand expira tupl-ul si trebuie eliminat
	};

	//setul de vecini selectati ca MPR
	class __declspec(dllexport) MPR_Set
	{
		public:
			int MPR_main_addr;//main address of a neighbor selected as MPR
	};

	//MPR Selector Set contine vecinii care au selectat acest nod ca MPR 
	class __declspec(dllexport) MPR_Selector_Set
	{
		public:
			int MS_main_addr;//main address of a node which has selected this node as MPR
			int MS_time; //cand expira tupl-ul si trebuie eliminat
	};

	//Topology Information Base
	//informatia este luata din mesajele TC si este folosita pentru calculul tabelei de rutare
	class __declspec(dllexport) Topology_Set
	{
		public:
			int T_dest_addr;//main address of a node which may be reached 
			int T_last_addr;//in one hop from the node with the main address T_last_addr
			int T_seq;//sequence number
			int T_time;//cand expira tupl-ul si trebuie eliminat
	};

	//Routing table calculation
	//based on Link Set and Topology Set, and even in the Neighbor Set, 2-hop NS, Multiple interface Association Information Base
	class __declspec(dllexport) Routing_table
	{
		public:
			int R_dest_addr; //destinatia
			int R_next_addr;
			/*the symmetric neighbor node with interface address R_next_addr
			  is the next hop node in the route to R_dest_addr, and that this
			  symmetric neighbor node is reachable through the local interface with
			  the address R_iface_addr.*/	
			int R_dist;//number of hops to destination
			int R_iface_addr;
	};

	class __declspec(dllexport) Node
	{
		public:
			int Main_addr;//adresa nodului
			//ne trebuie si lista de interfete a nodului, in afara de main address
			//vector<char*> Ifaces; //maxim 5
			//char* Receiving_iface_addr;// adresa interfetei pe care s-a primit mesajul
			HELLO_message* hello;
			TC_message* tc;
		

			//vector<Duplicate_Set> D_set;//Duplicate Set-ul nodului, are  doar 20 de intrari
			//vector<Interface_Association_Set> I_set;
			vector<Link_Set> L_set;
			vector<Neighbor_Set> N_set;
			vector<_2hop_Neighbor_Set> _2hop_set;
			vector<MPR_Set> Mpr_set;
			vector<MPR_Selector_Set> MS_set;
			int MS_ANSN;//Advertised  Neighbor Set
			vector<Topology_Set> T_set;
			vector<Routing_table> R_table;

			int Message_sequence_number; //numar unic de identificare pentru fiecare mesaj venit de la un anumit expeditor 
												//la fiecare mesaj nou el este  incrementat
			
			//dupa ce cream nodul trebuie sa adaugam interfetele
			Node();
			Node(int);//setam main address 
			//void setIfaces(char** ifs);//returneaza numarul de interfete ale nodului
			//MID_message* generate_MID(char addr[15]);
			//void process_MID(MID_message);
			HELLO_message*& generate_HELLO( );
			void process_HELLO(HELLO_message*);
			TC_message* generate_TC( );
			void process_TC(TC_message*);
			void Routing_table_creation();
	};

	class __declspec(dllexport) Molecula_topologie
	{
		private:
			int x;
			int y;
		public:
			Molecula_topologie(){
			x=0;
			y=0;
			}

			void setXY(int a, int b)
			{
				x=a;
				y=b;
			}

			int getX(){ return x; }
			int getY(){ return y; }
	 };
}