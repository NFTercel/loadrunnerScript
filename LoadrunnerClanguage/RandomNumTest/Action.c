Action()
{
	int randomNum_id;

	randomNum_id=rand();

	lr_output_message("�������������%d",randomNum_id);

	lr_output_message("���ò�����%d",lr_eval_string("{randomNum_id}"));

	return 0;
}
