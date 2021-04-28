<%@ Page Language="C#" MasterPageFile="~/Site.master" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="headContent" ContentPlaceHolderID="head" Runat="Server">
       <script>
        function validate(sender, args) {
            var quantity = document.getElementById('<%=txtQty.ClientID%>').value;
            if (isNaN(quantity)) {
                args.IsValid = true;
            } else {
                args.IsValid = false;
            }
        }
    </script>
</asp:Content>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:ScriptManagerProxy ID="ScriptManagerProxy1" runat="server" />

    <table style="width: 100%;">
        <tr>
            <td><h2 class="DDSubHeader">Suppliers</h2></td>
            <td><h2 class="DDSubHeader">Inventory</h2></td>
            
        </tr>
        <tr>
            <!--Suppliers gridview-->
            <td>
                <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="SupplierId" DataSourceID="SqlDataSource1" CellPadding="4" ForeColor="#333333" GridLines="None">
                    <AlternatingRowStyle BackColor="White" />
                    <Columns>
                        <asp:BoundField DataField="SupplierId" HeaderText="SupplierId" InsertVisible="False" ReadOnly="True" SortExpression="SupplierId" />
                        <asp:BoundField DataField="CompanyName" HeaderText="CompanyName" SortExpression="CompanyName" />
                        <asp:BoundField DataField="Country" HeaderText="Country" SortExpression="Country" />
                        <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
                    </Columns>
                    <EditRowStyle BackColor="#2461BF" />
                    <FooterStyle BackColor="#507CD1" ForeColor="White" Font-Bold="True" />
                    <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                    <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
                    <RowStyle BackColor="#EFF3FB" />
                    <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
                    <SortedAscendingCellStyle BackColor="#F5F7FB" />
                    <SortedAscendingHeaderStyle BackColor="#6D95E1" />
                    <SortedDescendingCellStyle BackColor="#E9EBEF" />
                    <SortedDescendingHeaderStyle BackColor="#4870BE" />
                </asp:GridView>
                <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Lab5ConnectionString %>" SelectCommand="SELECT * FROM [Suppliers]"></asp:SqlDataSource>
            </td>
            <!--Inventory gridview-->
            <td>
            <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="InventoryId" DataSourceID="SqlDataSource2" ForeColor="#333333" GridLines="None">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="InventoryId" HeaderText="InventoryId" InsertVisible="False" ReadOnly="True" SortExpression="InventoryId" />
                    <asp:BoundField DataField="SupplierID" HeaderText="SupplierID" SortExpression="SupplierID" />
                    <asp:BoundField DataField="Item" HeaderText="Item" SortExpression="Item" />
                    <asp:BoundField DataField="UnitsInStock" HeaderText="UnitsInStock" SortExpression="UnitsInStock" />
                </Columns>
                <FooterStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#FFCC66" ForeColor="#333333" HorizontalAlign="Center" />
                <RowStyle BackColor="#FFFBD6" ForeColor="#333333" />
                <SelectedRowStyle BackColor="#FFCC66" Font-Bold="True" ForeColor="Navy" />
                <SortedAscendingCellStyle BackColor="#FDF5AC" />
                <SortedAscendingHeaderStyle BackColor="#4D0000" />
                <SortedDescendingCellStyle BackColor="#FCF6C0" />
                <SortedDescendingHeaderStyle BackColor="#820000" />
            </asp:GridView>
            <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:Lab5ConnectionString %>" SelectCommand="SELECT * FROM [Inventory]"></asp:SqlDataSource>
            </td>
        </tr>
        <tr>
            <td>
                <!--quantity textbox-->
                Enter Quantity:<asp:TextBox ID="txtQty" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="Enter Quantity" ControlToValidate="txtQty"></asp:RequiredFieldValidator>
                <asp:CustomValidator ID="CustomValidator1" runat="server" ErrorMessage="Enter quantity in numbers" ControlToValidate="txtQty"></asp:CustomValidator>
            </td>
            <td>
                <!--button to display-->
                <asp:Button ID="btnReorder" runat="server" Text="Get Reorder List" />
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <h3>Reorder Details</h3>
                <asp:GridView ID="GridView3" runat="server" AutoGenerateColumns="False" CellPadding="4" ForeColor="#333333" GridLines="None" DataSourceID="SqlDataSource3">
                    <AlternatingRowStyle BackColor="White" />
                    <Columns>
                        <asp:BoundField DataField="Item" HeaderText="Product Name" SortExpression="Item" />
                        <asp:BoundField DataField="CompanyName" HeaderText="Supplier Name" SortExpression="CompanyName" />
                        <asp:BoundField DataField="UnitsInStock" HeaderText="Quantity" SortExpression="UnitsInStock" />
                    </Columns>
                    <EditRowStyle BackColor="#7C6F57" />
                    <EmptyDataTemplate>
                        No items need to be re-ordered
                    </EmptyDataTemplate>
                    <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
                    <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
                    <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
                    <RowStyle BackColor="#E3EAEB" />
                    <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
                    <SortedAscendingCellStyle BackColor="#F8FAFA" />
                    <SortedAscendingHeaderStyle BackColor="#246B61" />
                    <SortedDescendingCellStyle BackColor="#D4DFE1" />
                    <SortedDescendingHeaderStyle BackColor="#15524A" />
                </asp:GridView>

                <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:Lab5ConnectionString %>" SelectCommand="SELECT Inventory.Item, Suppliers.CompanyName, Inventory.UnitsInStock FROM Inventory INNER JOIN Suppliers ON Inventory.SupplierID = Suppliers.SupplierId WHERE (Inventory.UnitsInStock &lt;= @quantity)">
                    <SelectParameters>
                        <asp:ControlParameter ControlID="txtQty" DefaultValue="0" Name="quantity" PropertyName="Text" />
                    </SelectParameters>
                </asp:SqlDataSource>

            </td>
        </tr>
    </table>
    


</asp:Content>


