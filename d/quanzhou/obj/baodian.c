//Cracked by Roath
// kuihua.c 葵花宝典
// Jay 8/12/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
        set_name("葵花宝典", ({ "kuihua baodian", "baodian", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是日月神教所藏的《葵花宝典》。\n");
                set("value", 5000);
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");

        }
}

int do_du(string arg)
{
	mapping skl;
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;
	int i,j;
	string *sname;

	if (!(arg=="kuihua baodian" || arg == "baodian" || arg == "book"))
	return 0;

        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("你要读什么？\n");
                return 1;
        }
*/
        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "偷偷摸摸翻出一本书在读。\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "边读书边骚首弄姿，好象在模仿女人。\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "边读书边把腰身扭来扭去。\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 25 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

        if( (int)me->query("neili") < 25) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

        pxlevel = me->query_skill("pixie-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }
	if(pxlevel <90) {
		write("你研读了一会儿，但是发现上面所说的对你而言太深了。\n");
		return 1;
        }

	skl = me->query_skills();
	sname  = keys(skl);

        for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80) {
			write("你有的功夫太差了，影响你的深休。\n");
			return 1;
		}
		if (skl[sname[i]] <100) j++;
		if (j>2) {
			write("你不够强的功夫太多，影响你的深休。\n");
			return 1;
		}
	}

        if( pxlevel > 199){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

        me->receive_damage("jing", 25);
	me->set("neili",(int)me->query("neili")-25);
        me->improve_skill("pixie-jian", (int)me->query_skill("literate", 1)/4+1);
        write("你研读《葵花宝典》，颇有心得。\n");
        return 1;
}

