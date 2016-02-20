//Cracked by Roath
//  cangshuge 藏书阁
// modified by aln

inherit ROOM;

string look_shujia();

#define BOOKS_TOC   "/doc/books/toc"
#define BOOKS_DIR "/doc/books/jy/"

private mapping jybooks = ([
        "bxj"   : "碧血剑",
        "fhwz"  : "飞狐外传",
        "lcj"   : "连城诀",
        "ldj"   : "鹿鼎记",
        "sdxl"  : "神雕侠侣",
        "sdyxz" : "射雕英雄传",
        "sjecl" : "书剑恩仇录",
        "tlbb"  : "天龙八部",
        "xajh"  : "笑傲江湖",
        "xkx"   : "侠客行",
        "yttlj" : "倚天屠龙记",
        "33jxt" : "三十三剑侠图",
]);

void create()
{
	set("short", "白鹿藏书阁");
	set("long", @LONG
这是一个非常宽畅的楼阁，一排又一排的书架(shujia)上整整齐齐地摆满了
书，令人目不暇给。樟木香味夹着墨香扑鼻而来，这里就是白鹿书院的藏书阁，
收藏着许多武学经典，武林中人，千万不可错过在此一睹为快的良机。
LONG
	);
        set("item_desc", ([
                "shujia" : (: look_shujia :),
        ]));

	set("exits", ([
		"down" : __DIR__"shuyuan",
	]));

	set("cost", 0);

        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");

	setup();
}

void init()
{
	add_action("do_read",      "read");
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_exercise",  "practice");
        add_action("do_exercise",  "lian");
        add_action("do_exercise",  "study");
        add_action("do_exercise",  "du");
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "你是来读书还是来练功啊？\n");
        return 1;
}

string look_shujia()
{
        this_player()->start_more(read_file(BOOKS_TOC));
        return "\n";
}

int do_read(string arg)
{
        string jydir, filename;
        int t;

        jydir = this_player()->query_temp("jy/books");

        if( !arg ) { 
                if( stringp(jydir) )
                        return notify_fail("你现在在读" + jybooks[jydir] + "。\n");
                else    return notify_fail("你先选定一本你想要读的书，指令为: read xxx(书的英文缩写)，然而read n(回数)。\n");
        }

        if( sscanf(arg, "%d", t) != 1 || arg == "33jxt" ) {
                if( member_array(arg, keys(jybooks)) == -1 )
                        return notify_fail("书架上没有这本书。\n");
                else { 
                        this_player()->set_temp("jy/books", arg);
                        write("你选了《" + jybooks[arg] + "》。\n");
                        return 1;
                }
        }

        if( !stringp(jydir) )
                return notify_fail("你先选定一本你想要读的书，指令为: read xxx(书的英文缩写)，然而read n(回数)。\n");

        filename = BOOKS_DIR + jydir + "/" + jydir + "-" + t + ".txt";
        if( file_size(filename) == -1 )
                return notify_fail(jybooks[jydir] + "没有这一回。\n");

	switch (MONEY_D->player_pay(this_player(), 200)) {
	        case 0:
                return notify_fail("请带点零用钱做捐款用！\n");
	        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	}

	log_file("BOOKS", sprintf("%s read %s.\n", this_player()->query("name"), filename));

	this_player()->start_more(read_file(filename));

	return 1;
}
