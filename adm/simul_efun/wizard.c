//Cracked by Kafei
// wiz.c

string wizhood(mixed ob)
{
	return SECURITY_D->get_status(ob);
}

// added by sdong, 11/18/98
int wizardp(mixed ob)
{
	return ( SECURITY_D->get_wiz_level(ob) > 0 );
}

int wiz_level(mixed ob)
{
	return SECURITY_D->get_wiz_level(ob);
}
