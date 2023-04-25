#pragma once

//обработка событий
const int evNothing = 0;// пустое сообщение
const int evMessage = 100;// непустое
const int cmAdd = 1;// добавить объект
const int cmDel = 2;// удалить объект
const int cmGet = 3;// вывести атрибут объектов
const int cmShow = 4;// вывести группу
const int cmMake = 6; // создать группу
const int cmQuit = 101; // выход

struct TEvent
{
	int what; // тип события
	int command; // код команды
	int message;
	int a; // параметр команды
};