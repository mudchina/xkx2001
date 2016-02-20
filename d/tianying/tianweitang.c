//Cracked by Roath
// room: tianweitang.c

inherit ROOM;

void create()
{
        set("short", "天微堂");
        set("long", @LONG
这里是天微堂，地上铺着深红的绒毯。几名配剑武士整齐的站在
两旁。天鹰教教主属下有内三堂，天微堂乃三堂之首堂，堂主是教主
殷天正的儿子殷野王。
LONG );

        set("exits", ([
                "east" : __DIR__"zoulang7",
		"west" : __DIR__"zoulang6",
		"north" : __DIR__"zoulang8",
        ]));

        setup();
        replace_program(ROOM);
}
