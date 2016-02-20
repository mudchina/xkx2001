//Cracked by Roath
//GU MU FROM SANTA
//houtang.C

inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", @LONG
只见堂上也是空荡荡的没甚麽陈设，只有东西两壁都挂著一幅画。
西壁画(hua1)中是两个姑娘。东壁上悬挂著的画像(hua2)是一位道
人.
LONG
	);

	set("item_desc", ([
	"hua1" : "\n
只见画中两个姑娘，一个二十五六岁，正在对镜梳装，另一个是
十四五岁的丫鬟，手捧面盆，在旁侍候。画中镜里映出那年长女郎容
貌极美，秀眉入鬓，眼角之间却隐隐带著一层杀气。你望了几眼，心
下不自禁的大生敬畏之念。

	"hua2" : "\n
这道人身材甚高，右手食指指著东北角，只是背脊向外，面貌却
看不见。其上隐约可见痰迹.
	]));

	 set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east" : __DIR__"shufang",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
