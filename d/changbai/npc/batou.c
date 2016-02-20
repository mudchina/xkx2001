//Cracked by Roath
// batou.c

inherit NPC;
int ask_caishen();
string ask_suobogun();


void create()
{
	set_name("赫尔苏", ({ "heersu", "ba tou" }) );
	set("gender", "男性" );
	set("age", 70);
	set("long", "这是一位须发班白的七旬老人。古铜色的皮肤，眼中透出刚毅坚强的目光。\n");
	set("nickname", "老把头" );

	set("shen_type", 1);
	set("str", 29);
	set("dex", 26);
	set("con", 24);
	set("int", 19);
	set("attitude","heroism");
       
        set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set("combat_exp", 10000);
        set_temp("apply/attack", 40);
	set_temp("apply/defense", 50);

	set("inquiry", ([
		"name"   : "我就是赫尔苏，你找我有什么事么？",
		"采参"   : (: ask_caishen :),
                "参"     : (: ask_caishen :),
		"索拨棍"   : (: ask_suobogun :),
                "鹿骨钎子"  : (: ask_suobogun :),
	]) );
	setup();
	add_money("silver", 10);
}


int ask_caishen()
{
        string myid = this_player()->query("id");

        command("secret " + myid);
        command("whisper " + myid + " " + 
                " 采参又叫“放山”，乃是一项既艰苦又危险的行当。深山老林中\n"
                "不但蠹虫猛兽甚多，一但遇到风雪天气，那更是凶多吉少！\n"
                "你如想采到参，须去长白大山之中，用索拨棍击打山草，寻找山参的\n"
                "踪迹，一但找到，需用鹿骨钎子才能将之起出，否则会伤到根须！\n");
 
        return 1;
}

string ask_suobogun()
{
        object obj, me = this_player();
        string myid;

        if( (int)me->query_temp("cbshen/ask_gun") > 0 )
                return "你不是已经问过我了吗，怎麽又来问？ \n";

        if( present("suobo gun", me) ) 
		return "你现在身上不是有了吗，怎麽又来问？ \n";

	if( present("suobo gun", environment()) ) 
	        return "地上这不有吗？ 你要的话就捡走吧。\n";

        myid = me->query("id");

        switch( me->query_temp("cbshen/blw") ) {
        case 1:
                command("nod " + myid);

                obj = new("/d/changbai/obj/sbgun");
                obj->set("owner", myid);
                obj->move(me);
                message_vision("$N交给$n一" + obj->query("unit") + obj->name() + "。\n", this_object(), me);

                obj = new("/d/changbai/obj/qianzi");
                obj->set("owner", myid);
                obj->move(me);
                message_vision("$N交给$n一" + obj->query("unit") + obj->name() + "。\n", this_object(), me);

                me->delete_temp("cbshen");

                return "不错，你果然心存诚意。这个索拨棍和鹿骨钎子就送给你吧！\n";
                break;
        case 2:
                command("haha " + myid);
                me->set_temp("cbshen/ask_gun", 2);
                return "你再去山神爷的灵位前祭拜一下。\n";
                break;

        case 3:
                command("disapp " + myid);
                me->set_temp("cbshen/ask_gun", 3);
                return "算了吧，这辈子你就别指望了。\n";
                break;
        default:
                break;
	}

        me->set_temp("cbshen/ask_gun", 1);
        return "你先去山神爷的灵位前祭拜一下，以示心存诚意吧！\n";
}

