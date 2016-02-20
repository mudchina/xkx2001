//Cracked by Roath
// hsstreet2
// qfy Oct 15, 97

inherit ROOM;

void create()
{
	set("short", "村外土路");
	set("long", @LONG
这里离村庄很远，左右道旁都是密林，在道路上投下大片阴影，感觉
甚是凉爽。一阵风紧，空中几片落叶飞舞。路旁依稀有几条小径通往林中。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"southeast" : __DIR__"hsforest7",
	"northeast" : __DIR__"hsforest1",
	"west" : __DIR__"hsstreet1",
	"east" : __DIR__"hsstreet3",
]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 2);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object ob, *inv, master;
	int i;

	if ( dir == "northeast" || dir == "southeast" )  {
		if ( objectp(ob=me->query("rided")) )
			return notify_fail(ob->name()+"身子太大了，进不了树林！\n");
		else {
			inv = all_inventory(me);
			for (i=0; i<sizeof(inv); i++) {
                		if ( (string)inv[i]->query("ridable") )
					return notify_fail(inv[i]->name()+"身子太大了，你背不进树林！\n");
			}
        	}

		if ( me->query("ridable") ) {
			if ( objectp(master=me->query_lord()) ) {
				tell_object(master, me->name()+"身子太大了，进不了树林！\n");
			}

			return notify_fail(me->name()+"身子太大了，进不了树林！\n");
		}
        }

        return ::valid_leave(me, dir);
}