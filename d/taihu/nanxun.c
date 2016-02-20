//Cracked by Roath
// /d/taihu/nanxun.c
// by aln  2 / 98

inherit ROOM;

void create()
{
    int i;
        set("short", "南浔镇");
        set("long", @LONG
湖州府自来文风甚盛，历代才士辈出，梁时将中国字分为平上去入四声的
沈约，元代书画皆臻极品的赵孟兆都是湖州人氏。当地又以产笔著名，湖州之
笔，徽州之墨，宣城之纸，肇庆端溪之砚，文房四宝，天下驰名。南浔镇虽是
湖州府的一个镇，却比寻常州县还大，镇上富户极多，著名的富室大族之中有
一家姓庄。
LONG
        );

        set("objects", ([
               "/d/hangzhou/npc/zhuang" : 1,
                
         ]));

        set("exits", ([
		"southeast" : "/d/hangzhou/road32",
		"north" : __DIR__"yixing",
        ]));

	set("outdoors", "taihu");

	set("cost", 2);
        setup();

	replace_program(ROOM);
}

