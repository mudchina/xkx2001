//Cracked by Roath
//kane

inherit ROOM;

int do_tanzhi();
void create()
{
	set("short", "弹指峰");
	set("long", @LONG
这里是整个桃花岛的最高点，居高临下，全岛景观尽收眼底。南边是海，向西
是一些光秃秃的岩石，东面北面都是花树，五色缤纷，不见尽头，只看得人头昏眼
花。峰顶有一块石碑，上有三个大字“弹指峰”，碑旁有一个石洞。洞口之上三个
大篆，虽然已磨损不少，但仍依稀可辨。细看之下原来是“清音洞”三字。
LONG
	);
	 set("exits", ([
                "enter" : __DIR__"qingyin",
                "southdown" : __DIR__"shanlu2",
        ]));
        
	set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));

	set("cost", 5);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

