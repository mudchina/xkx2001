//Cracked by Roath
//kane

inherit ROOM;

void create()
{
	set("short", "墓室");
	set("long", @LONG
墓室正中是一道香案，案上供着黄药师夫人冯氏灵位，灵前有两盏琉璃灯，
昏黄的灯光映着黄药师手绘的夫人遗像(portrait)。墓室中壁间案头尽是古物珍
玩，名画书法，无一不是价值连城的精品。黄药师当年纵横湖海，搜罗的奇珍异
宝不计其数，这时都供在亡妻墓室之中；只见珍宝中那些明珠美玉、翡翠玛瑙之
属在灯光下发出淡淡光芒。灵案后一道毡帷，后面是冯氏的玉棺。
LONG
	);
        
	set("item_desc", ([
        "portrait" : 
"\n黄夫人冯氏面目栩栩如生；当真是天妒红颜，一代佳人竟尔早夭。\n"
        ]));

        set("exits", ([
                "out" : __DIR__"didao",
        ]));

        set("objects", ([
                "/d/taohua/obj/coffin" : 1,
        ]));
	
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object ob;
	
	ob = present("coffin", environment(me));
	ob->delete("opened");  
	ob->set("long", "这是一具由整块白玉雕成的石棺，晶莹光洁，实是旷世难寻的珍物。\n");
  	
	return ::valid_leave(me, dir);
}

int is_container() { return query("opened"); };

