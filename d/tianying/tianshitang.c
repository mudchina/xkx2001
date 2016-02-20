//Cracked by Roath
// room: tianshitang.c

inherit ROOM;

void create()
{
        set("short", "天市堂");
        set("long", @LONG
这里是天市堂，地上铺着深红的绒毯。几名配剑武士整齐的站在
两旁。天鹰教教主属下有内三堂，天微堂乃三堂之末，堂主是教主殷
天正的师弟李天垣。
LONG );

        set("exits", ([
		"west" : __DIR__"zoulang7",
        ]));

        setup();
        replace_program(ROOM);
}
