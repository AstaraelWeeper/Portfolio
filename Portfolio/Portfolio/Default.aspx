<%@ Page Title="Reptiles!" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Portfolio._Default" %>


<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>Visit our pet shop</h1>
        <p class="lead">Choose your own forever reptile!</p>
        <p><a href="/Contact.aspx" class="btn btn-primary btn-lg">Learn more &raquo;</a></p>
    </div>
    <div class="ShopAreas">
        <div class="container">
            <h2>Browse our products</h2>
            <p>Take a look around - we have a wide selection of snakes, lizards, and food supplies.</p>
            <div class="row">
                <div class="col-md-4">
                    <h2>Snakes</h2>
                    <div class="thumbnail">
                        <img src="http://www.captivebredreptileforums.co.uk/attachments/ball-royal-pythons/14091d1307616791-some-photos-stock_albino_cinnamon001.gif">
                    </div>
                    <!--//thumbnail 1.2-->

                    <p>
                        <a class="btn btn-default" href="/Products/Index.aspx?categoryID=3">Learn more &raquo;</a>
                    </p>
                </div>
                <div class="col-md-4">
                    <h2>Lizards</h2>
                    <div class="thumbnail">
                        <img src="http://cdn.instructables.com/FVI/EY6Z/FQMXFHGB/FVIEY6ZFQMXFHGB.LARGE.jpg" />
                    </div>
                    <!--//thumbnail 1.2-->
                    <p>
                        <a class="btn btn-default" href="/Products/Index.aspx?categoryID=4">Learn more &raquo;</a>
                    </p>
                </div>
                <div class="col-md-4">
                    <h2>Food</h2>
                    <div class="thumbnail">
                        <img src="https://encrypted-tbn3.gstatic.com/images?q=tbn:ANd9GcSdh4L3i6NRajUv03F-KUx_yOASYiyI7Ex6KcmEk15vuGe5oTCKkQ">
                    </div>
                    <!--//thumbnail 2.1-->
                    <p>
                        <a class="btn btn-default" href="/Products/Index.aspx?categoryID=2">Learn more &raquo;</a>
                    </p>
                </div>
            </div>
        </div>
    </div>

    <div class="learn-more">
        <div class="container">
            <div class="row">


                <div class="col-md-6">
                    <h3>Guides</h3>
                    <p>Need some advice on how to look after your new pet?</p>
                    <p><a href="#">Click here for guides</a></p>
                </div>
                <div class="col-md-6">
                    <h3>Trust and Safety</h3>
                    <p>We only buy from reputable breeders</p>
                    <p><a href="#">Learn about where our animals come from</a></p>
                </div>
            </div>
        </div>
    </div>
</asp:Content>
