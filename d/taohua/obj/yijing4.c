//Cracked by Roath
// yijing.c

inherit ITEM;

void create()
{
	set_name( "易经《系辞篇》", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册易经。上面写着：\n
　　天尊地卑，乾坤定矣。卑高以陈，贵贱位矣。 动静有常，刚柔断矣。
方以类聚，物以群分，吉凶生矣。 在天成象，在地成形，变化见矣。

　　鼓之以雷霆，润之以风雨，日月运行，一寒一暑，乾道成男，坤道成
女。

　　乾知大始，坤作成物。

　　乾以易知，坤以简能。

    易则易知，简则易从。 易知则有亲，易从则有功。 有亲则可久，有
功则可大。 可久则贤人之德，可大则贤人之业。

    易简，而天下矣之理矣；天下之理得，而成位乎其中矣。
\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 25, 	// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	120,	// the maximum level you can learn
		]) );
	}
}
