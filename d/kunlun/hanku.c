//Cracked by Roath
// room: /mingjiao/hanku.c

inherit ROOM;

void create()
{
        set("short", "汉哭山");
        set("long", @LONG
这里已达昆仑北麓的尽头，山外便是茫茫大漠。据说汉代昭君出塞到
达此处时，无限感伤，曾痛哭一天一夜，天地为之变色，故而此山又名“
汉哭”。更奇之处，山侧一块巨石上竟留有永不褪去的泪痕，故此称为“
泪痕石(leihenshi)”。
LONG );

        set("exits", ([
                "north" : __DIR__"?????",
                "southdown" : __DIR__"yinshandao",
        ]));

        set("item_desc", ([
                "leihenshi"    : "这是一块暗青色的巨石，约有
普通圆桌大小，仔细看时，发现上面斑斑点点，确实好似泪痕一般。\n",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}