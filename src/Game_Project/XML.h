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

static vector <int> xmlValues;
//using namespace std;
void XML(std::string dificultad) {
	Niveles lvl;
	//rapidxml::file<> xmlFile(RESOURCE_FILE(filename));
	rapidxml::xml_document<> doc;
	std::ifstream file("XMLFile.xml");
	std::stringstream buffer; //creo un buffer
	buffer << file.rdbuf(); //algo q hace tona con el buffer
	file.close(); //cierro el fichero --> idk why
	std::string content(buffer.str()); //asigno a la variable contenido la info del buffer en string
	doc.parse<0>(&content[0]); //transformo lo guardado en la variable contenido a codigo entendible y accesible

	rapidxml::xml_node<> *pRoot; //creo variable puntero detipo nodo de xml
	pRoot = doc.first_node();//asigno a esa variable puntero el primer nodo del fichero xml(gameScene)
	rapidxml::xml_node<> *pNode; //creo otro puntero de tipo nodo xml

	std::cout << "DIFICULTAD NIVEL" << std::endl;
	//segun que nivel ha escogido, printea unos atributos o otros. Solo comento elif del Easy porque los de masson iguales.
	if (dificultad == "easy") {

		std::cout << pRoot->first_node("Easy")->name() << ':' << std::endl; //printeo el nodo llamado "Easy"
		pNode = pRoot->first_node("Easy"); //asigno al puntero pNode el nodo con nombre "Easy".

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			std::cout << pAttr->name() << ":" << pAttr->value() << std::endl;
			xmlValues.push_back(stoi(pAttr->value()));
			
		}cout << "xmlValues Size: " << xmlValues.size();
		//xmlVal = xmlValues;
		//cout << "xmlVal Size: " << xmlVal.size();
	}
	else if (dificultad == "medium") {

		std::cout << pRoot->first_node("Medium")->name() << ':' << std::endl; //printeo el nodo llamado "Medium"
		pNode = pRoot->first_node("Medium"); //asigno al puntero pNode el nodo con nombre "Medium".

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			std::cout << pAttr->name() << ":" << pAttr->value() << std::endl;
			xmlValues.push_back(stoi(pAttr->value()));
		}

	}
	else if (dificultad == "hard") {

		std::cout << pRoot->first_node("Hard")->name() << ':' << std::endl; //printeo el nodo llamado "Hard"
		pNode = pRoot->first_node("Hard"); //asigno al puntero pNode el nodo con nombre "Hard".

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			std::cout << pAttr->name() << ":" << pAttr->value() << std::endl;
			xmlValues.push_back(stoi(pAttr->value()));
		}
	}
}
