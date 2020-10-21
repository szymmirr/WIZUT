<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WebApplication2.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
&nbsp;
        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem Text="+" Value="1"></asp:ListItem>
            <asp:ListItem Text="-" Value="2"></asp:ListItem>
            <asp:ListItem Text="*" Value="3"></asp:ListItem>
            <asp:ListItem Text="/" Value="4"></asp:ListItem>
        </asp:DropDownList>
        &nbsp;<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        &nbsp;
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="=" />
        
        <br />
        <br />
        <asp:Label ID="Label1" runat="server" Text="0"></asp:Label>
        <asp:Label ID="Label2" runat="server" Text="Sesja: "></asp:Label>
        <asp:Label ID="Label3" runat="server" Text="0"></asp:Label>
    </div>
    </form>
</body>
</html>
