<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'cook2.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <%
    	String cookieValue = null;
    	Cookie[]cookies = request.getCookies();
    	if(cookies!=null&&cookies.length>0){
    		for(Cookie cookie: cookies)
    		{
    			if("cookiePath".equals(cookie.getName())){
    				cookieValue = cookie.getValue();
    			}
    		}
    	}
    	if(cookieValue!=null)
    	{
    		out.print(cookieValue);
    	}else{
    		out.print("没有指定的cookie");
    	}
     %>
  </body>
</html>
