Action()
{
	web_set_max_html_param_len("50000");

	//��ȡ����ע����id��album_id���Id
	web_reg_save_param_ex("ParamName=shop_id",
						"LB=\"shop_id\":\"",
						"RB=\",\"watermark\":",
						"NotFound=warning",
						SEARCH_FILTERS,
						LAST);

	//��ȡ����ע��������ά��code_id
	web_reg_save_param_ex("ParamName=code_id",
						"LB=code_",
						"RB=_",
						"NotFound=warning",
						SEARCH_FILTERS,
						LAST);

	//��ȡ����עA�����Id
	web_custom_request("get_shop_id",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);


//	lr_output_message(lr_eval_string("{shop_id}"));
	lr_output_message(lr_eval_string("{code_id}"));

//https://www.wsxc.me/service/account/get_my_attention_code.jsp?&shop_id=A201812080953300270014587&page_index=1&client_type=ios&token=N0I5MjQwRTM4N0FDRkIzOEY3NUM2MkZCNDdENjRCRUEwMUIwRDQzOEZCNDA5NTVFOUY3RTUwNEZBNDUxM0QyQkQzNjg4OTc5NjZFMUVFMzYyODREQ0JFNTY1Rjg0OTQ4&version=2302&_=1548224360023


	//��ȡ����עA�Ķ�ά��code
	web_custom_request("get_code_id",
					   "URL={requestUrl}/service/account/get_my_attention_code.jsp?shop_id={code_id}&client_type=ios&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	//Bɨ���עA
	web_custom_request("use_code_id",
					   "URL={requestUrl}/service/account/attention.jsp?follow_code={code_id}&user_id=&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);



	web_reg_save_param_ex("ParamName=shop_id_b",
						"LB=shop_id\":\"",
						"RB=\",\"user_icon\":",
						"NotFound=warning",
						"Ordinal=1",
						SEARCH_FILTERS,
						LAST);



	//A�ķ�˿�б�
	web_custom_request("get_new_fans",
					   "URL={requestUrl}/service/album/get_album_list.jsp?act=get_new_fans&client_type=ios&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	//Aͨ��B
/*	web_custom_request("accept_shop_id",
					   "URL={requestUrl}/service/album/album_operation.jsp?act=accept&shop_id={shop_id_b}&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);
*/

	return 0;
}
