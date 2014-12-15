
<!--#if expr="$QUERY_STRING = /interlude_id=([a-zA-Z0-9_]+)&imageurl=((http.*\.)(jpe?g|png|[tg]iff?|svg))/" -->
    
    <!--#set var="INTERLUDE_ID" value="$1" -->
    
    <!--#set var="IMAGE_URL" value="$2" -->

    <!--#if expr="$QUERY_STRING = /service=([a-zA-Z]+)/" -->
        <!--#set var="SERVICE" value="$1" -->
    <!--#else -->
        <!--#set var="SERVICE" value="en" -->
    <!--#endif -->

    <div id="interlude-container" style="margin-top: 1em"></div>
    <script>
        require(['jquery-1'], function ($) {

            $('body').addClass('full-width-mode');

            var minWidth = 768;
            var serviceId = '<!--#echo var="SERVICE" -->';

            var textValues = [];
            textValues['en'] = {
                before: '<' + 'p><' + 'strong>INTERACTIVE VIDEO: Choose you journey through the video by clicking on the panels when they appear before the timer runs out. If you don\'t make a selection, you will be taken onto the next section automatically.<' + '/strong><' + '/p>',
                after: '<' + 'p>This interactive video is a new technology being trialled by the <' + 'a href="http://www.bbc.co.uk/partnersandsuppliers/connectedstudio ">BBC Connected Studio innovation programme<' + '/a> and is best viewed with the latest version of <' + 'a href="http://get.adobe.com/flashplayer/">Flash<' + '/a> It does not currently work on iOS or Android mobile devices or tablets. If you have feedback about the interactive video experience, <' + 'a href="http://www.bbc.co.uk/partnersandsuppliers/connectedstudio/contactus">please let us know<' + '/a><' + '/p><' + 'p>You can find the non-interactive version of this content below.<' + '/p>',
                noSupport: 'Your browser does not support this interactive video.'
            };
            var currentLangText = (serviceId in textValues) ? textValues[serviceId] : textValues['en'],
                interludeContainer = document.getElementById('interlude-container');

            function browserIsWorthyOfInterlude () {
                return (
                    ($('body').width() >= minWidth) &&
                    (window.matchMedia) &&
                    (Function.prototype.bind) &&
                    !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
                ) ||
                (/IE /.test(navigator.userAgent) && /Trident\/[^34]/.test(navigator.userAgent) );
            }

            function displayNotSupportedMsg() {
                interludeContainer.innerHTML = '<p><strong>' + currentLangText.noSupport + '</strong></p>';
            }

            function displayInterludeHolder () {
                interludeContainer.innerHTML = currentLangText.before + '<a href="http://content.interlude.fm/player/bbc/<!--#echo var="INTERLUDE_ID" -->/iframe.html" class="interlude-holder" target="_blank"><img src="<!--#echo var="IMAGE_URL" -->" /></a>' + currentLangText.after;
            }

            /*
                Temporary requirement until the domestic News site goes fully responsive.
            */
            function hideResponsiveNotSupportedInclude () { 
                $('.newsspec_9779__not-supported').hide();
            }

            function conditionallyDisplayInterlude () {
                hideResponsiveNotSupportedInclude();
                if (browserIsWorthyOfInterlude()){
                    displayInterludeHolder();
                }
                else {
                    displayNotSupportedMsg();
                }
            }

            conditionallyDisplayInterlude();

        });
    </script>
<!--#else -->
    <!--#if expr="$QUERY_STRING = /interlude_id=([a-zA-Z0-9_]+)/" -->
        <!-- IMAGE URL NOT FOUND -->
    <!--#else -->
        <!-- INTERLUDE ID NOT FOUND -->
    <!--#endif -->
<!--#endif -->