<%@ page language="java" import="java.util.*" pageEncoding="utf-8" session="false"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'cookie.jsp' starting page</title>
    
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
		Cookie[] cookies = request.getCookies();
		if(cookies != null && cookies.length > 0)
		{
			for(Cookie cookie: cookies)
			{
				out.print(cookie.getName()+":"+cookie.getValue());
				out.print("<br>");
			}
		}else
		{
			out.print("没有一个Cookie,正在创建返回");
	     	Cookie cookie = new Cookie("lkd","123");
	     	cookie.setMaxAge(10);
	    	response.addCookie(cookie);  			
		}

     %>
  </body>
</html>
