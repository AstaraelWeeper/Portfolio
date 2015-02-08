<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="ViewProduct.aspx.cs" Inherits="Portfolio.Products.ViewProduct" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <asp:HyperLink runat="server" ID="lnkBack" NavigateUrl="~/Products/Index.aspx?categoryID=">Back To</asp:HyperLink>
                <div class="form-horizontal">
                    <h4><asp:Label runat="server" ID="lblProductName" /></h4>
                    <dl class="dl-horizontal">
                        <dt>Description:</dt>
                        <dd><asp:Label runat="server" ID="lblDescription" /></dd>
                        <dt>Price:</dt>
                        <dd><asp:Label runat="server" ID="lblPrice" /></dd>
                        <dt>Category:</dt>
                        <dd><asp:Label runat="server" ID="lblCategory" /></dd>
                    </dl>
                </div>
            </div>
        </div>
    </div>
</asp:Content>
