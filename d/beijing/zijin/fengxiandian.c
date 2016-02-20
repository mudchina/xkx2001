//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "奉先殿");
	set("long",  @LONG
这是皇家供奉祖宗的地方。殿中轻烟缭绕，正中的桌子上摆放着
皇家列祖列宗的灵位。
LONG
	);

	set("exits", ([
        "south" : __DIR__"guang4",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
