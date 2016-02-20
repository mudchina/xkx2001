// Change by Server
//

inherit F_CLEAN_UP;

#define EVAL_FILE	"/tmp/tmp_eval.c"

int
main(object me, string arg)
{
    /* clean up first */
    seteuid(geteuid(me));
    if (file_size(EVAL_FILE) != -1)
	rm (EVAL_FILE);
    if (find_object(EVAL_FILE))
	destruct(find_object(EVAL_FILE));

    write_file(EVAL_FILE, sprintf("mixed eval() { return %s; }\n", arg));
    printf("Result = %O\n", EVAL_FILE->eval());
    return 1;
}

int help()
{
	write(@TEXT
÷∏¡Ó∏Ò Ω£∫eval <expression>

TEXT
	);
	return 1;
}
