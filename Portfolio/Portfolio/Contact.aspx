<%@ Page Title="Contact" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Contact.aspx.cs" Inherits="Portfolio.Contact" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <h2><%: Title %>.</h2>
    <h3>Rachel's Reptile Shop.</h3>
    <address>
        22 Example Lane<br />
        London, NW1 2NA<br />
    </address>

    <address>
        <strong>Support:</strong>   <a href="mailto:Support@example.com">Support@example.com</a><br />
        <strong>Queries:</strong> <a href="mailto:Queriesg@example.com">Queries@example.com</a>
    </address>
</asp:Content>
