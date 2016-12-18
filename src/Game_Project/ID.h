#pragma once
#include <iostream>

enum class ObjectID : const int {
	S_00, // ID_Fondo
	S_01, // ID_Titulo
	S_02, // ID_PlayButton
	S_03, // ID_EasyButton
	S_04, // ID_MediumButton
	S_05, // ID_HardButton
	S_06, // ID_ExitButton
	S_07, // ID_bg niveles
	S_08, // ID_Cabeza
	S_09, // ID_Cuerpo
	S_10, // ID_Cola
	S_11, // ID_Manzana
	S_12  // ID_Pared
	
};
inline std::ostream &operator<<(std::ostream &os, const ObjectID &id) { return os << int(id); };
inline std::istream &operator>>(std::istream &is, ObjectID &id) { return is >> reinterpret_cast<int&>(id); };