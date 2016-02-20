//Cracked by Roath
// animal_data.c
// snowbird, Dec. 1999
// 1.1.1.1

#include <ansi.h>
inherit ITEM;

// provide 2 functions 

mixed *GetAnimalData(int i);  // retrieve the data indexed by i
int SetupAnimalData (object obj, int i);  // setup the data after retrieval

//  麻雀  飞禽
//  毒蛇  蛇类
//  白骆驼 家畜
//  红马 家畜

// This is a table of animal data

// data1 => 飞禽
// data2 => 家畜
// data3 => 野兽
//********************************************************
static mixed animal_data1 = ({
/*   0      1        2        3      4      5      6   7   8    9  10*/
/* Index  Name      name1   name2   Race   age    str int con dex  exp */
  ({ 0,   "麻雀", "ma que", "bird", "飞禽", 3   ,  5,  5,  5, 20,  500,}),
});

static mixed animal_long1 = ({ 
    "一只叽叽喳喳，飞来飞去的小麻雀。\n",
});
//********************************************************
static mixed animal_data2 = ({
/*   0      1        2        3          4      5     6   7    8   9   10*/
/* Index   Name    name1   name2        Race    age  str int  con dex  exp */
  ({ 0,   "黄羊", "lamb", "huang yang", "家畜", 11  , 20, 10, 20, 20,  2000, }),
});

static mixed animal_long2 = ({ 
    "一只野黄羊，正低头认真地吃着草。\n",
});
//********************************************************
static mixed animal_data3 = ({
/*   0      1        2        3        4      5     6   7   8   9   10*/
/* Index   Name    name1   name2     Race    age   str int con dex  exp */
  ({ 0,   "母狼", "mu lang","wolf",  "野兽", 15  , 30, 10, 20, 20,  5000, }),
  ({ 1,   "老虎", "lao hu", "tiger", "野兽", 15  , 40, 15, 30, 40,  500000, }),
  ({ 2,   "豹子", "bao zi", "bao",   "野兽", 15  , 35, 15, 30, 50,  500000, }),
  ({ 3,   "狮子", "shi zi", "lion",  "野兽", 15   ,50, 15, 30, 50,  500000, }),
});

static mixed animal_long3 = ({ 
    "这是一头灰色的母狼，正用红色的眼睛盯着你，不时发出令人胆战的嗥声！\n",  
    "这是一只吊睛白额猛虎，色彩斑斓，时不时用利爪挠挠地，长啸一声。\n",
    "这是一头金钱豹子，颈上虬筋凸腱，敏捷雄健，不安分地踱来走去。\n",
    "这是一只雄狮，傲然卧于青石上，半眯双目，四下顾盼，确有睥睨万兽的王者之气。\n",
});
//********************************************************


mixed *GetAnimalData(int i) 
{
	mixed animal;
	int x, y;

	switch (i/100)
	{
		case 0:
		   y = i;
   	   animal = animal_data1[y];
	      x = sizeof(animal);
	      animal += ({animal_long1[y]});
    		break;
		case 1:
		   y = i-100;
   	   animal = animal_data2[y];
	      x = sizeof(animal);
	      animal += ({animal_long2[y]});
			break;
		case 2:
		   y = i-200;
   	   animal = animal_data3[y];
	      x = sizeof(animal);
	      animal += ({animal_long3[y]});
			break;
	}
    return animal;
}

int SetupAnimalData (object obj, int i)
{
	mixed animal;
	int x;

	// set to default
    obj->set_name("野兽", ({"ye shou", "shou"}));
    obj->set("race", "野兽");
    obj->set("age", 100);
    obj->set_weight(150000);
    obj->set("long", "一只面目不清的野兽。\n");
    obj->set("combat_exp", 1000);
    obj->set("wildness", 5);
    obj->set("loyalty", 5);
    obj->set("auto_follow",1);

	// get the animal data and redo setup
	animal = GetAnimalData(i);
   x = sizeof(animal) - 1;
	obj->set_name(animal[1], ({animal[2], animal[3]}));
	obj->set("race", animal[4]);
	obj->set("age", animal[5]);
	obj->set("str", animal[6]);
	obj->set("int", animal[7]);
	obj->set("con", animal[8]);
	obj->set("dex", animal[9]);
	obj->set("combat_exp", animal[10]);
	obj->set("long", animal[x]);

    return 1;
}

void create()
{
       seteuid(getuid()); 
}
