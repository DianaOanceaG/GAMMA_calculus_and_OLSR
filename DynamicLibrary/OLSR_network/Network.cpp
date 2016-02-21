#include "Network.h"
//#include "Olsr.h"
#include<vector>

using namespace System;
using namespace System::Windows::Forms;

vector<OLSR_protocol::Node> Nodelist;
vector<OLSR_protocol::Molecula_topologie> topologie;
//OLSR_protocol::Node Nodelist [10];
OLSR_protocol::Node getNode(int adr)
{
	OLSR_protocol::Node p(adr);
	return p;
}

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	OLSR_network::Network form;
	Application::Run(%form);
	
	//Nodelist.reserve(10);//indiferent de numarul de noduri ales initial, maximul este 10 deoarece se mai pot adauga elemente noi


}
