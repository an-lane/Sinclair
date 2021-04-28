<%@ Page Language="VB" AutoEventWireup="false" CodeFile="Default.aspx.vb" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Ashley Nixon 2222 Project 5</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>

            <table style="width: 100%;">
                <tr>
                    <!-- display all the suppliers -->
                    <td>
                        <h1>Suppliers</h1>
                        <asp:GridView ID="GridView1" runat="server" CellPadding="5" AutoGenerateColumns="False" DataKeyNames="SupplierID" DataSourceID="SqlDataSource1" ForeColor="#7C98B3" GridLines="None" AlternatingRowStyle-BackColor="#CEE5F2" BackColor="#637081">
                            <AlternatingRowStyle BackColor="#CEE5F2"/>
                            <Columns>
                                <asp:BoundField DataField="SupplierID" HeaderText="SupplierID" InsertVisible="False" ReadOnly="True" SortExpression="SupplierID" />
                                <asp:BoundField DataField="CompanyName" HeaderText="CompanyName" SortExpression="CompanyName" /> 
                                <asp:BoundField DataField="Country" HeaderText="Country" SortExpression="Country" />
                                <asp:BoundField HeaderText="ContractName" SortExpression="ContractName" DataField="ContractName" />
                            </Columns>
                            <EditRowStyle BackColor="#536B78" />
                            <FooterStyle BackColor="#637081" />
                            <HeaderStyle BackColor="#536b78" />

                        </asp:GridView>
                        
                        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Suppliers]"></asp:SqlDataSource>
                        
                    </td>
                    <!-- display the entire inventory -->
                    <td>
                        <h1>Inventory</h1>
                        <asp:GridView ID="GridView2" runat="server" CellPadding="5" AutoGenerateColumns="False" DataKeyNames="InventoryID" DataSourceID="SqlDataSource2" ForeColor="#536B78" GridLines="None" AlternatingRowStyle-BackColor="#7c98b3" BackColor="#CEE5F2">
                            <AlternatingRowStyle BackColor="#accbe1" />
                            <Columns>
                                <asp:BoundField DataField="InventoryID" HeaderText="InventoryID" InsertVisible="false" ReadOnly="true" SortExpression="InventoryID" />
                                <asp:BoundField DataField="SupplierID" HeaderText="SupplierID" SortExpression="SupplierID" />
                                <asp:BoundField DataField="Item" HeaderText="Item" SortExpression="Item" />
                                <asp:BoundField DataField="UnitsInStock" HeaderText="UnitsInStock" SortExpression="UnitsInStock" />
                            </Columns>
                            <EditRowStyle BackColor="#536b78" />
                            <FooterStyle BackColor="#637081" />
                            <HeaderStyle BackColor="#536b78" />

                        </asp:GridView>

                        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Inventory]"></asp:SqlDataSource>

                    </td>
                </tr>
            <!-- allow the user to enter a quanitity, click the "Get Reorder List" button, and display all items at or below the quantity entered-->
                <tr>
                    <td>
                        <!-- textbox for quantity -->
                        Enter Quantity:
                        <asp:TextBox ID="txtQty" runat="server"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="Enter Quantity" ForeColor="Red" ControlToValidate="txtQty"></asp:RequiredFieldValidator>
                        <asp:CustomValidator ID="CustomValidator1" runat="server" ErrorMessage="Enter quantity in numbers" ClientValidationFunction="validate()" ControlToValidate="txtQty"></asp:CustomValidator>
                    </td>
                    <td>
                        <!-- Button for display list -->
                        <asp:Button ID="Button1" runat="server" Text="Get Reorder List" />
                    </td>
                </tr>
                <tr>
                    <td colspan="2">
                        <h3>Reorder Details</h3>
                        <asp:GridView ID="GridView3" runat="server" AutoGenerateColumns="False" BackColor="#ACCBE1" BorderColor="#536B78" BorderWidth="1px" CellPadding="2" DataSourceID="SqlDataSource3" ForeColor="#536B78" GridLines="None">
                            <AlternatingRowStyle BackColor="#accbe1" />
                            <Columns>
                                <asp:BoundField DataField="Item" HeaderText="Item" SortExpression="Item" />
                                <asp:BoundField DataField="CompanyName" HeaderText="CompanyName" SortExpression="CompanyName" />
                                <asp:BoundField DataField="UnitsInStock" HeaderText="UnitsInStock" SortExpression="UnitsInStock" />
                            </Columns>
                            <EmptyDataTemplate>
                                <span style="color: red;">No items need to be re-ordered</span>
                            </EmptyDataTemplate>
                            <FooterStyle BackColor="#accbe1" />
                            <HeaderStyle BackColor="#637081" />
                            <SortedAscendingCellStyle BackColor="#7c98b3" />
                            <SortedAscendingHeaderStyle BackColor="#536b78" />
                            <SortedDescendingCellStyle BackColor="#accbe1" />
                            <SortedDescendingHeaderStyle BackColor="#637081" />
                        </asp:GridView>

                        <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT Inventory.Item, Suppliers.CompanyName, Inventory.UnitsInStock FROM Inventory INNER JOIN Suppliers ON Inventory.SupplierID = Suppliers.SupplierID WHERE (Inventory.UnitsInStock = @quantity)">
                            <SelectParameters>
                                <asp:ControlParameter ControlID="txtQty" DefaultValue="0" Name="quantity" PropertyName="Text" />
                            </SelectParameters>
                        </asp:SqlDataSource>

                    </td>
                </tr>

            </table>
            

        </div>
    </form>
</body>
</html>

