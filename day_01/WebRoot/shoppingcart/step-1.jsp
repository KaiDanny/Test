<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'step-1.jsp' starting page</title>
    
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
    <h4>Step1:选择购买的图书</h4>
    <form action="processStep1" metnod="post">
	    <table border="1" cellpadding="10" cellspacing="0">
	    	<tr>
	    		<td>书名</td>
	    		<td>购买</td>
	    	</tr>
	    	<tr>
	    		<td>Java</td>
	    		<td><input type="checkbox" name="book" value="java"></td>
	    	</tr>
	    	<tr>
	    		<td>Oracle</td>
	    		<td><input type="checkbox" name="Oracle" value="Oracle"></td>
	    	</tr>
	    	<tr>
	    		<td>Struts</td>
	    		<td><input type="checkbox" name="Struts" value="Struts"></td>
	    	</tr>
	    	<tr>
	    		<td colspan="2"><input type="submit" value="Submit"></td>
	    	</tr>    		    		    		    	
	    </table>
    </form>
  </body>
</html>
