//Cracked by Roath
// room: /mingjiao/daqing.c

inherit ROOM;

void create()
{
        set("short", "大青山");
        set("long", @LONG
此处树木仍是十分浓密，但已渐趋低矮，只有一人多高，正是高山
常见现象。头顶日头甚是毒辣，照在林木之上，隐隐有一层青气腾
起。远远望去，有一种说不出的诡异。
LONG );

        set("exits", ([
                "southwest" : __DIR__"qingshuigou",
                "eastdown" : __DIR__"luyuhe",
                "southdown" : __DIR__"jishi",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}