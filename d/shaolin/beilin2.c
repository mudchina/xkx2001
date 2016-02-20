//Cracked by Roath
// Room: /d/shaolin/beilin2.c
// Date: YZC 96/01/19

inherit ROOM;


void check_trigger();
void close_passage();
void reset();
int do_push(string);
int do_say(string);
string look_tower();
string look_stone();


void create()
{
	set("short", "西碑林");
	set("long", @LONG
这里是一大片碑林。虽说是碑林，主要是少林历代高僧的
佛塔灵藏(tower)。一座座佛塔约有二三人高，有汉白玉的，
花冈石的，精工雕凿，薄薄的浮雕面上飞禽走兽，佛谒禅诗，
诸佛众生，可谓无所不包。底座有须弥座的，也有莲花座的，
各态纷呈。佛塔间疏疏落落的立着几块碑(stone)，有的题着
几句诗。
LONG
	);

	set("exits", ([
		"east" : __DIR__"taijie",
	]));

	set("outdoors", "shaolin");
	set("item_desc",([
		"tower"		:	(: look_tower :),
		"stone"		:	(: look_stone :),
	]));

	set("cost", 2);
	setup();
}


void init()
{
	add_action("do_push", "push");
	add_action("do_pull", "pull");
	add_action("do_say", "say");
}

void check_trigger()
{
	object room;

	if( (int)query("up_trigger")==4
	&&	(int)query("down_trigger")==3
	&&	!query("exits/down") ) {
		message("vision", "佛塔忽然发出轧轧的声音，向一侧缓缓移开，"
			"向下露出一个黑洞洞的入口。\n", this_object() );
		set("exits/down", __DIR__"beilin3");
		if( room = find_object(__DIR__"beilin3") ) {
		        room->set("exits/up", __FILE__);
		        message("vision", 
"头顶上的石板忽然发出轧轧的声音，露出一个光亮亮的洞口。"
"一块块踏脚石从墙壁中凸了出来，形成一个向上的阶梯。\n",room );
		}
		delete("poem_said");
		delete("up_trigger");
		delete("down_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "佛塔忽然发出轧轧的声音，缓缓地移回原处，"
		"将向下的洞口盖住了。\n", this_object() );
	if( room = find_object(__DIR__"beilin3") ) {
		room->delete("exits/up");
		message("vision", "头顶上的石板忽然发出轧轧的声音，"
			"墙上的石块又缓缓地收了回去，阶梯消失了。\n", room );
	}
	delete("exits/down");
}


int do_pull(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="stone" && (int)query("poem_said")==1 ) {
		write("你试着扳动这块石碑，发现可以往上抬......\n");
		return 1;
	}
	if( sscanf(arg, "stone %s", dir)==1 && (int)query("poem_said")==1 ) {
		if( dir=="up" ) {
			message_vision("$N将石碑往上抬...，忽然「喀」一声石碑又移回原位。\n",
				this_player());
			add("up_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你要将石碑推向那个方向？\n");
			return 1;
		}
	}
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="stone" && (int)query("poem_said")==1 ) {
		write("你试着扳动这块石碑，发现可以往下压......\n");
		return 1;
	}
	if( sscanf(arg, "stone %s", dir)==1 && (int)query("poem_said")==1 ) {
		if( dir=="down" ) {
			message_vision("$N将石碑往下压...，忽然「喀」一声石碑又移回原位。\n",
				this_player());
			add("down_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你要将石碑推向那个方向？\n");
			return 1;
		}
	}
}

int do_say(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="清晨入古寺，初日照高林" ) {
		write("你可真有诗兴 !\n");
		return 1;
	}

	if( arg=="上报四重恩，下济三途苦" ) {
		write("只听四周的佛塔，石碑发出隆隆隆的响声，地面猛烈震动起来。\n");
		add("poem_said", 1);
		return 1;
	}
}

void reset()
{
	::reset();
	delete("poem_said");
	delete("up_trigger");
	delete("down_trigger");
}

string look_tower()
{
	return
	"\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　一切世界佛，悉发菩提心，　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　上报四重恩，下济三途苦，　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　无边大法力，渡劫升极乐，　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　愿以此功德，庄严佛净土。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n";
}

string look_stone()
{
	return
	"\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　清晨入古寺，初日照高林。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　曲径通幽处，禅房花木深。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　山光悦鸟性，潭影空人心。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　万籁此俱寂，惟闻钟磐音。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n";
}

