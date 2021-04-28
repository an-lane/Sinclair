
<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Ashley Nixon-CSS2222-Coding Club Registration Form</title>
    <style type="text/css">
        body {background-color :#f1bf98; text-align:center;}
        .regForm { background-color:#bacba9; 
                   padding: 12px; 
                   display:inline-block; 
                   border: 3px solid #717568;
                   border-radius: 25px;
        }
        h1 { color:#3f4739;}
        .btn { background-color:#e1f4cb; border:1px solid #717568; border-radius: 20px; padding:10px; box-shadow: 1px 2px #3f4739; font-weight:bold;}
        span {text-align:left;}
     
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class ="regForm">
            <h1>Coding club registration form</h1>
            <span>
            <p><!--Name-->
               <asp:Label ID="YourNameLabel" runat="server" Text="Your Name:" AssociatedControlID="YourNameTextBox" AccessKey="N"></asp:Label>
                <asp:TextBox ID="YourNameTextBox" runat="server" Columns="40" MaxLength="40"></asp:TextBox>
                <asp:RequiredFieldValidator runat="server" ID="NameValid" ControlToValidate="YourNameTextBox" ErrorMessage="Name Required" ForeColor="Red" Text="*"/>
            </p>
            <p><!--Email-->
                <asp:Label ID="YourEmailLabel" runat="server" Text="Your Email:" AssociatedControlID="YourEmailTextBox" AccessKey="N"></asp:Label>
                <asp:TextBox ID="YourEmailTextBox" runat="server" Columns="40" MaxLength="40"></asp:TextBox>
                <asp:RequiredFieldValidator ID="MailEntry" runat="server" ControlToValidate="YourEmailTextBox" ErrorMessage="Mail Required" ForeColor="Red" Text="*" />
                <asp:RegularExpressionValidator ID="regexEmailValid" runat="server" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*" 
                    ControlToValidate="YourEmailTextBox" ForeColor="Red" Text="*" ErrorMessage="Invalid Email" />
            </p>
            <p><!--Phone-->
                <asp:Label ID="YourPhoneLabel" runat="server" Text="Your Phone:" AssociatedControlID="YourPhoneTextBox" AccessKey="N"></asp:Label>
                <asp:TextBox ID="YourPhoneTextBox" runat="server" Columns="40" MaxLength="40"></asp:TextBox>
                <asp:RequiredFieldValidator ID="phoneEmpty" runat="server" ControlToValidate="YourPhoneTextBox" ErrorMessage="Phone Required" ForeColor="Red" Text="*" />
                <asp:RegularExpressionValidator ID="phoneValid" runat="server" ControlToValidate="YourPhoneTextBox" ErrorMessage="Invalid Phone Number" 
                    ForeColor="Red" Text="*" ValidationExpression="^[2-9]\d{2}-\d{3}-\d{4}$" />
            </p>
            </span>
            <p><!--Button Submit Form and Clear Form-->
                <asp:Button ID="btnSubmitForm" class="btn" runat="server" Text="Submit Form" AccessKey="S" OnClick="btnSubmitForm_Click" />
                <asp:Button ID="btnClearForm" class="btn" runat="server" Text="Clear Form" AccessKey="C" OnClick="btnClearForm_Click" />
            </p>
            <p>
                <asp:Label ID="MessageLabel" runat="server" Visable="False" style="font-size:25px; color:#3f4739;"></asp:Label>
                <asp:ValidationSummary ID="ValidationSummary1" runat="server" ForeColor="Red" Font-Size="25" />
            </p>
            
        </div>
    </form>
</body>
</html>
