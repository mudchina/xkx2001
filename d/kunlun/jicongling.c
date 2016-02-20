//Cracked by Roath
// room: /mingjiao/jicongling.c

inherit ROOM;

void create()
{
        set("short", "极葱岭");
        set("long", @LONG
此处又是一雄伟高山。西来的强风终年不断，故西侧甚是贫瘠，乱石
嶙峋之间只有稀稀落落的矮灌木和杂草。东侧倒是郁郁葱葱，对比鲜明。
传闻此地毒虫甚多，不可久留。
LONG );

        set("exits", ([
                "eastdown" : __DIR__"yinshandao",
        ]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}