//Cracked by Roath
// marry.c
//
// Zhuang@XKX 081396

#include <dbase.h>

int is_married()
{
	return mapp(query("spouse"));
}

int is_spouse_of(object ob)
{
	return( query("spouse/id") == ob->query("id")
		&&  ob->query("spouse/id") == query("id") );
}
