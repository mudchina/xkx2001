//Cracked by Roath
// Room: /shguan2.c


inherit ROOM;

void create()
{
	set("short", "老龙头");
	set("long", @LONG
老龙头是万里长城最东端。澄海楼巍峨高踞城头，楼上“雄襟万里”的
横匾居高临下，直俯大海。自澄海楼筑有一石城逐级而下伸入大海，站在石
城终端楼平台上四眺，海天一色，无边无际，气象万千。
LONG
	);

	
	set("exits", ([
		"northwest" : __DIR__"shguan1",
                "south" : "/d/beijing/yidao3",
	]));

        set("objects",([
                 __DIR__"npc/feng" : 1,
        ]));
        
	set("outdoors", "changbai");
        set("cost", 3);

	setup();
        replace_program(ROOM);
}


