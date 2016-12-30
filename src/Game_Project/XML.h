#pragma once
#include "ID.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Logger.h"
#include "Assert.h"
#include "Resource.h"
#include <XML/rapidxml_utils.hpp>

using namespace Logger;
using namespace rapidxml;

static vector <int> xmlValues; //Vector para guardar los datos leidos desde el XML
//using namespace std;

static void XML(std::string dificultad) {
	//Niveles lvl;
	//rapidxml::file<> xmlFile(RESOURCE_FILE(filename));
	rapidxml::xml_document<> doc;
	std::ifstream file("XMLFile.xml");
	std::stringstream buffer; //creo un buffer
	buffer << file.rdbuf(); //algo q hace tona con el buffer
	file.close(); //cierro el fichero XML que se ha acabado de leer.
	std::string content(buffer.str()); //asigno a la variable contenido la info del buffer en string
	doc.parse<0>(&content[0]); //transformo lo guardado en la variable contenido a codigo entendible y accesible

	rapidxml::xml_node<> *pRoot; //Puntero a un nodo del fichero XML
	pRoot = doc.first_node(); //asigno a esa variable puntero el primer nodo del fichero xml(gameScene)
	rapidxml::xml_node<> *pNode; //creo otro puntero de tipo nodo xml

	std::cout << "DIFICULTAD NIVEL" << std::endl;
	
	if (dificultad == "Easy") {
		std::cout << pRoot->first_node("Easy")->name() << ':' << std::endl; //imprimo el nodo llamado "Easy"
		pNode = pRoot->first_node("Easy"); //asigno al puntero pNode el nodo con nombre "Easy".
		int i = 0;
		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			std::cout << pAttr->name() << ":" << pAttr->value() << std::endl;
			xmlValues.push_back(stoi(pAttr->value()));
			i++;
		}cout << "xmlValues Size: " << xmlValues.size();
		//xmlVal = xmlValues;
		//cout << "xmlVal Size: " << xmlVal.size();
	}
	else if (dificultad == "Medium") {

		std::cout << pRoot->first_node("Medium")->name() << ':' << std::endl; //printeo el nodo llamado "Medium"
		pNode = pRoot->first_node("Medium"); //asigno al puntero pNode el nodo con nombre "Medium".

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			std::cout << pAttr->name() << ":" << pAttr->value() << std::endl;
			xmlValues.push_back(stoi(pAttr->value()));
		}

	}
	else if (dificultad == "Hard") {

		std::cout << pRoot->first_node("Hard")->name() << ':' << std::endl; //printeo el nodo llamado "Hard"
		pNode = pRoot->first_node("Hard"); //asigno al puntero pNode el nodo con nombre "Hard".

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			std::cout << pAttr->name() << ":" << pAttr->value() << std::endl;
			xmlValues.push_back(stoi(pAttr->value()));
		}
	}
}
