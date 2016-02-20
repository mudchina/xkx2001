//Cracked by Roath
// langmei.c 榔梅园 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "榔梅园");
	set("long", @LONG
	这里种满了榔梅树，花色深浅一如桃花，蒂垂丝作海棠状。榔和梅本是山
中的两种树，相传有一天玄武帝把梅枝插在榔干上，久而复合，成此异种。据说榔
梅果核不可以带出武当山，违者必遭不昌。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"taiziyan",
		"southup" : __DIR__"wuyaling",
                "westup" : __DIR__"nanyan",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/shouyuan" : 1]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

