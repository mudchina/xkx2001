//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

   me->apply_condition("gb_job", duration - 1);

   inv = all_inventory(me);

   for (i=0; i<sizeof(inv); i++) {
		if ( inv[i]->is_container() && present("mihan", inv[i]) ) obj=present("mihan", inv[i]);
		if ( inv[i]->query("id") == "mihan" ) obj = inv[i];
   }

   if ( objectp(obj) && random(me->query("kar")) < 3 && random(40) < 5 ) {
   	switch( random(2) ) {
   	case 0:	
		message("vision", me->name()+"身上突然掉下一封信。\n", environment(me), ({me}) );
		break;
   	case 1:
		message("vision", "你见到有人鬼鬼祟祟地由"+me->name()+"身上扒走一封信。\n", environment(me), ({me}) );
		break;
	}

	call_out("let_know", 3, me);	
	destruct(obj);
    }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

void let_know(object me)
{
	tell_object(me, HIR "你伸手往怀中一摸，惊觉密函不见了！\n" NOR);
}
