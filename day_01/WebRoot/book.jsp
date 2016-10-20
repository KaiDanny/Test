<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'book.jsp' starting page</title>
    
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
    <h4>Book detail page</h4>
    Book:<%= request.getParameter("book") %>
    <br>
    <br>
    <a href="books.jsp">return</a>
    <%
    	String book = request.getParameter("book");
    	//把书的信息以Cookie方式传回给浏览器，删除一个cookie
    	//1,确定删除的cookie
    	//前提，aa开头的Cookie数量大于或等于5
    	Cookie[] cookies = request.getCookies();
    	//保存所有aa开头的cookie
    	List<Cookie> bookCookies = new ArrayList<Cookie>();
    	//用来保存和books.jsp传入的book匹配的那个cookie
    	Cookie tempCookie = null;
    	if(cookies != null&&cookies.length > 0){
    		for(Cookie c: cookies){
    			String cookieName = c.getName();
    			if(cookieName.startsWith("aa")){
    				bookCookies.add(c);
    				if(c.getValue().equals(book)){
    					tempCookie = c;
    				}
    			}
    		}
    	}
    	//且若从books.jsp页面传入的book不在aa的cookie中删除较早的那个cookie
    	//(aa 数组的第一个cookie)
    	if(bookCookies.size() >= 5 && tempCookie == null){
    		tempCookie = bookCookies.get(0);
    	}
    	//若在其中，则删除该cookie
    	if(tempCookie != null){
    		tempCookie.setMaxAge(0);
    		response.addCookie(tempCookie);
    	}
    	//把从books。jsp传入的book作为一个cookie返回
    	Cookie cookie = new Cookie("aa"+book,book);
    	response.addCookie(cookie);
     %>
  </body>
</html>
