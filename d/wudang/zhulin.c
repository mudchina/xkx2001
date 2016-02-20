//Cracked by Roath
// zhulin.c 竹林深处
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "竹林深处" );
	set("long", @LONG
这里四周都是竹林，一条鹅卵石铺成的小路向竹林深处延伸。微风轻拂
动青竹叶发出刹刹的声音，显得一片清凉宁静。清晨的薄日从林梢透射下来
，照得人身上懒洋洋的。你走过草丛的旁边，不时擦过几片青草，幽幽静静
之中，小鸟的鸣啼倏然响起，旋而归于沉寂。
LONG
	);
	set("exits", ([
		"south" : __DIR__"hs_xiaolu",
		"north" : __DIR__"xiaolu2",
	]));
	
	setup();
	replace_program(ROOM);
}
