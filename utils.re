# example rule for calling 
# msiExecCmd
# msiFreeExecCmd

execCmd(*cmd, *args) {
	*argStr = "";
	foreach(*arg in *args) {
		*argStr = *argStr++execCmdArg(*arg)++" ";
	}
	*argStr = substr(*argStr, 0, strlen(*argStr) - 1);

	*e = errorcode(msiExecCmd(*cmd, *argStr, "null", "null", "null", *status));
	msiGetStdoutInExecCmdOut(*status, *out);
	msiGetStderrInExecCmdOut(*status, *err);

	msiFreeExecCmd(*status);

	(*e, *out, *err);
}
