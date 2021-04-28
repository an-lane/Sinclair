<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">

</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h1>Connect</h1>
    <p>How well do you know the other businesses in your local area? Creating stragetic connections can help fortify your 
        reputation and your business.</p>
    
    <asp:Image ID="Image1" runat="server" ImageUrl="Images/photo-of-people-near-wooden-table-3184418.jpg" CssClass="business" />
    <h2>How Can We Help?</h2>
    <p>Business Exchange Network is where small business owners build trusted relationships and generate referrals. Join 
        for free and connect with other businesses in the local Dayton area.</p>
    <form id="form1" runat="server">
        <table style="width: 60%; border:1px solid black">
            <tr>
                <td colspan="2" style="text-align:center;"><h2>Join the Network</h2></td>
            </tr>
    <tr>
        <td style="text-align:right; font-weight: bold; width:40%;">First Name</td>
        <td style="text-align:left;"><asp:TextBox id="FirstName" runat="server" /><asp:RequiredFieldValidator ID="ReqFirst" runat="server" ErrorMessage="First Name Required" ControlToValidate="FirstName" Font-Bold="True" Font-Underline="True" ForeColor="Red" /></td>
    </tr>
    <tr>
        <td style="text-align:right; font-weight: bold;">Last Name</td>
        <td style="text-align:left;"><asp:TextBox id="LastName" runat="server" /><asp:RequiredFieldValidator ID="ReqLast" runat="server" ErrorMessage="Last Name Required" ControlToValidate="LastName" Font-Bold="True" Font-Underline="True" ForeColor="Red" /></td>
    </tr>
    <tr>
        <td style="text-align:right; font-weight: bold;">Company</td>
        <td style="text-align:left;"><asp:TextBox id="BusinessName" runat="server" /><asp:RequiredFieldValidator ID="ReqBusiness" runat="server" ErrorMessage="Please Enter Company Name" ControlToValidate="BusinessName" Font-Bold="True" Font-Underline="True" ForeColor="Red" /></td>
    </tr>
    <tr>
        <td style="text-align:right; font-weight: bold;">Email</td>
        <td style="text-align:left;"><asp:TextBox id="Email" runat="server" /><asp:RegularExpressionValidator ID="ValEmail" runat="server" ErrorMessage="Invalid Email Format" ControlToValidate="Email" ValidationExpression="\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*" Font-Underline="True" Font-Bold="True" ForeColor="Red" /></td>
    </tr>
    <tr>
        <td style="text-align:right; font-weight: bold;">Phone</td>
        <td style="text-align:left;"><asp:TextBox id="Phone" runat="server" /><asp:RegularExpressionValidator ID="ValPhone" runat="server" ErrorMessage="Enter Valid Phone Number" BorderStyle="None" ControlToValidate="Phone" ValidationExpression="^[01]?[- .]?(\([2-9]\d{2}\)|[2-9]\d{2})[- .]?\d{3}[- .]?\d{4}$" Font-Bold="True" Font-Underline="True" ForeColor="Red" /></td>
    </tr>

            <tr>
                <td colspan="2">
                    <asp:Label ID="lblStatus" runat="server" Text=""></asp:Label>
                </td>
            </tr>
    <tr>
        <td colspan="2" style="text-align:center;">
            <asp:Button ID="btnSubmit" runat="server" Text="Submit" BorderStyle="Groove" BorderWidth="2px"  onclick="btnSubmit_Click"/>
        </td>
    </tr>
</table>
    </form>
</asp:Content>