<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Index.aspx.cs" Inherits="Portfolio.Products.Index" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div class="container">
        <div class="row">
            <h4><asp:Label runat="server" ID="lblPageTitle">Products</asp:Label></h4>
            <div class="col-md-12">
                <asp:GridView ID="grvProduct" runat="server" AutoGenerateColumns="False">
                    <Columns>
                        <asp:BoundField ReadOnly="true" HeaderText="Product" DataField="Name" />
                        <asp:HyperLinkField DataNavigateUrlFields="ProductId" DataNavigateUrlFormatString="ViewProduct.aspx?id={0}" HeaderText="View" Text="View" />
                    </Columns>
                </asp:GridView>
            </div>
        </div>
    </div>
</asp:Content>
