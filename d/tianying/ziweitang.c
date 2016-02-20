//Cracked by Roath
// room: ziweitang.c

inherit ROOM;

void create()
{
        set("short", "紫微堂");
        set("long", @LONG
这里是紫微堂，地上铺着深红的绒毯。几名配剑武士整齐的站在
两旁。天鹰教教主属下有内三堂，紫微堂乃三堂之第二堂，堂主是教
主殷天正的亲女殷素素。
LONG );

        set("exits", ([
                "east" : __DIR__"zoulang6",
        ]));

        setup();
        replace_program(ROOM);
}
