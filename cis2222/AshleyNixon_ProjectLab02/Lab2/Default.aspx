<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>CIS 2222: Ashley Nixon Lab 02</title>
    <style>    
        .outline {outline: 1px solid black;}
        .border {
            border: 1px solid black;
            width: 200px;
            margin: 10px;
            text-align: center;
            padding:10px;
        }
    </style>
</head>
<body>
    <form id="form" runat="server">
        <div = "outline">
            <h1>CIS 2222</h1>
            <h2>Ashley Nixon</h2>
            <table class="border">
                <tr><td>Interest Calculator</td></tr>
                <tr><td>&nbsp;</td></tr>
                <tr><td>Loan <u>A</u>mount</td><td><asp:TextBox ID="txtLoanAmount" runat="server" Width="100px"></asp:TextBox></td></tr>
                <tr><td>&nbsp;</td></tr>
                <tr><td><u>I</u>nterest Rate</td></tr>
                <tr><td colspan="2" class="border" style="width:100px;"><asp:RadioButtonList ID="rlInterestRate" runat="server">
                    <asp:ListItem Value="5">5%</asp:ListItem>
                    <asp:ListItem Value="6">6%</asp:ListItem>
                    <asp:ListItem Value="7" Selected="True">7%</asp:ListItem>
                        </asp:RadioButtonList></td></tr>
                <tr><td>&nbsp;</td></tr>
                <tr><td>Number of <u>Y</u>ears</td><td><asp:DropDownList ID="ddlYears" runat="server">
                    <asp:ListItem Value="10">10</asp:ListItem>
                    <asp:ListItem Value="15">15</asp:ListItem>
                    <asp:ListItem Value="20" Selected="True">20</asp:ListItem>
                        </asp:DropDownList></td></tr>
                <tr><td>&nbsp;</td></tr>
                <tr><td><asp:Button ID="btnCalculation" runat="server" Text="Calculate Interest" OnClick="btnCalculation_Click" /></td>
                    <td><asp:Button ID="btnReset" runat="server" Text="Reset" OnClick="btnReset_Click" /></td>
                </tr>
            </table>
        </div>
    </form>
    <p><asp:Label ID="lblOutput" runat="server" Text=""></asp:Label></p>
</body>
</html>
