<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
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
    	//若可以获取到请求参数name,则打印出欢迎信息，把登陆信息存储到cookie中，并设置cookie的最大时效30s
    	String name = request.getParameter("name");
    	if(name != null && !name.trim().equals(""))
    	{
    		out.println("hello:" + name);
    		Cookie cookie = new Cookie("name",name);
    		cookie.setMaxAge(30);
    		response.addCookie(cookie);
    	}else
    	{
    		//从Cookie中读取用户信息,若存在则打印信息
    		Cookie[] cookies = request.getCookies();
    		if(cookies != null && cookies.length > 0)
    		{
    			for(Cookie cookie : cookies)
    			{
    				String cookieName = cookie.getName();
    				if("name".equals(cookieName))
    				{
    					String val = cookie.getValue();
    					name = val;
    				}
    			}
    		}
    	}
    	if(name != null && !name.trim().equals(""))
    	{
    		out.println("hello:"+name);
    	}else{
    		//若没有请求参数，也没有Cookie则重定向到login.jsp
    		response.sendRedirect("login.jsp");
    	}
     %>
  </body>
</html>
