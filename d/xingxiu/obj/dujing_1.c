//Cracked by Roath
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("『星宿毒经』", ({ "du jing", "jing" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "册");
                set("long",
"\n                 『星宿毒经』\n\n"
"　　毒经为星宿宝典，凡以此经及经内所载药物私与他人，即视为欺师灭祖、\n"
"背叛师门。对叛师之徒，虽上天入地，吾弟子必予诛之。外人持有本经者，吾\n"
"弟子见一个杀一个，见十个杀十个，断不容私阅本门宝典者苟存于世。\n\n"
"　　　　　　　　　　　　　　　　　　　　　　　　　　星宿老仙　丁\n"
"【蒙汗药】\n"
"　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。\n"
"　药性：不致命，可使人昏厥。对内力极强者，药效不显。\n\n"
"【炼心弹】\n"
"　用法：作为暗器使用（throw <target>）。\n"
"　药性：硫磺硝磷所制火弹，使敌皮开肉绽，毒性随即钻入肌肉。\n"
"  制法：用硫磺和蛇胆、或蛛丝等捏成。（make lianxin dan）。\n\n"
"【碧磷针】\n"
"　用法：作为暗器使用（throw <target>）。\n"
"　药性：毒针，喂有剧毒。如不服解药，有性命之忧。\n"
"  制法：用绣花针和蛇胆、或蛛丝等搓成。（make bilin zhen）。\n\n"
"【逍遥三笑散】\n"
"　用法：作暗器使用（tan<弹> <target>  ）。\n"
"　药性：无色无味毒粉，杀人无救。但强敌能把毒震回，你会反受其害。\n"
"  制法：用本门宝物蓝玉钵，按次序放进五毒（毒蛇胆、沙虫壳、蝎子壳，\n"
"        毒蛛丝、蜈蚣壳）便可制成。\n\n"
"【蝮蛇涎】\n"
"  取法：从昏迷的蝮蛇口中挤到蓝玉钵中（squeeze[or ji] snake to bo）。\n"
"  用法：直接涂抹到武器上（coat[or tu] <weapon >）。\n\n"
"【清心散】\n"
"　用法：吞服（eat san）。\n"
"　药性：为本门独门解药，可解炼心弹和星宿毒掌之毒。\n"
"    \n");
		set("value", 300);
		set("material", "paper");
		set("skill", ([
                        "name": "poison",      // name of the skill
                        "exp_required": 0,      // minimum combat experience req
                        "jing_cost":    20,     // jing cost every time study th
                        "difficulty":   10,     // the base int to learn this sk
                        "max_skill":    30      // the maximum level you can lea
                ]) );
        }
	setup();
}
