//Cracked by Roath
// animal_inherit.c
// snowbird Dec. 1999
// 1.1.1.1

#include <ansi.h>
#include <dbase.h>
#include <name.h>

int setup_animal(int i);

int setup_animal(int i) 
{
	object animal;

	// must get uid before clone a new object
   seteuid(getuid(this_object()));
	// load up my database file
   animal=new("/d/wanshou/clone/animal_data");
	animal->SetupAnimalData(this_object(), i);

	// destory the database object
	destruct(animal);
	return 1;
}

