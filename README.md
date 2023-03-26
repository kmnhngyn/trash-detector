# Trash Detector
Trash Detector ist ein Uniprojekt im Rahmen des HTW Wahlpflicht-Mastermoduls Wissensmanagement im Studiengang Wirtschaftsinformatik. Inhalt und Ziel des Moduls war die Erstellung eines Hardware-Prototypen mit einem Microcontroller und die Verwendung von Machine Learning.

*Hinweis: Der hier vorgestellte Prototyp basiert zu diesem Zeitpunkt auf hard-gecodeten Ausgabewerten und gibt keine Echtdaten aus. Dies kann jedoch erzielt werden, wenn eine Hardware mit mehr Arbeitsspeicher verwendet wird. Die hier verwendete Hardware bietet nur einen begrenzten Speicher von 1 MB an.*

## 1 Einleitung
Müll ist ein globales Problem, das sich auf die Umwelt und die Gesellschaft auswirkt. Der Anstieg des Müllaufkommens und die begrenzten Möglichkeiten zur Entsorgung haben negative Auswirkungen auf die Gesundheit der Menschen, die Tiere und die Umwelt.(1) Um diesen Herausforderungen zu begegnen, haben sich diverse Länder und Unternehmen darauf konzentriert, Technologien und Verfahren zur Müllerkennung und zum Recycling zu entwickeln.(2) Müllerkennungs- und Recyclingtechnologien helfen dabei, Abfall zu reduzieren, wertvolle Ressourcen zurückzugewinnen und die Umweltbelastung zu minimieren. In diesem Zusammenhang sind auch innovative Lösungen wie künstliche Intelligenz und maschinelles Lernen im Bereich der Müllerkennung und des Recyclings auf dem Vormarsch.\
Dieses Projekt ist ein Prototyp und der erste Schritt für die Verwendung von Technologien zur Müllerkennung.

### 1.1 Motivation
Mithilfe von Technologie können Vebraucher dabei unterstützt werden, bereits während der Entsorgung von Müll ihren Teil zum Recycling und somit zu einer nachhaltigeren Welt beizutragen. Dieser Protoyp soll ein erster Schritt für den Einsatz von Microcontrollern in der Müllerkennung sein, um Abfall zu reduzieren, wertvolle Ressourcen zurückzugewinnen und die Umweltbelastung zu minimieren. 

### 1.2 Ziel des Projektes
Das Ziel dieses Projektes ist die Müllerkennung mithilfe von Machine Learning (TinyML) und eines Microcontrollers.
Die Effizienz und Effektivität der Müllsortierung soll verbessert werden und dadurch ein Beitrag zu einer nachhaltigeren Zukunft geleistet werden. Durch die Verwendung von Microcontrollern zur Müllerkennung und zum Recycling kann Abfall besser klassifiziert werden und somit eine automatische Trennung und Weiterverarbeitung von Abfall ermöglichen. Dies wiederum reduziert die Müllentsorgungskosten, maximiert den Wert wiederverwendbarer Ressourcen und reduziert die Umweltbelastung.

Konkret soll der Prototyp dazu beitragen, dass der Müllsortierprozess effizienter wird, indem er die Müllerkennung automatisiert und somit menschliche Fehler minimiert. Durch die Erkennung von verschiedenen Müllarten auf der Grundlage von Merkmalen wie Farbe, Form und Struktur kann eine Trennung und Weiterverarbeitung von Abfall ermöglicht werden.

Umgesetzt wird dies durch die visuelle Aufnahme von verschiedenen Müllarten. Bildmaterial von Müll wird dabei klassifiziert und erhalten Labels, womit später das TinyML-Modell trainiert und getestet wird. Über die Kamera wird nahezu live der Müll erkannt und die Müllart auf einem separaten Display ausgegeben.

Ziel ist nicht die Erstellung eines fertigen Prototypen oder eine vollwertig funktionierende Hard- und/oder Software.

## 2 Aufbau und Vorbereitung des Prototypen
In diesem Abschnitt wird gezeigt, welche Vorbereitungen getroffen werden müssen, um den Prototypen zum Laufen zu bringen.

### 2.1 Hardwarekomponenten
Für den Prototypen sind drei Hardwarekomponenten relevant, um den Müll zu erkennen und die erkannte Müllart auf einem Display auszugeben:
1. Microcontroller **Nano 33 BLE Sense**
2. Kameramodul **OV7675***
3. **M5StickC PLUS.**

Die Kommunikation zwischen dem Nano 33 und dem M5Stick wird über Bluetooth umgesetzt, wobei der Nano 33 als zentrales Gerät und der M5Stick als Peripheriegerät fungiert.

1. Der Microcontroller Nano 33 BLE Sense von Arduino ist das Herzstück des ganzen. Auf diesem Controller wird der Code für die Erkennung des Mülls raufgespielt und zusätzlich der Code für die Bluetoothkommunikation zum Display (M5StickC PLUS).
<img src="images/arduino_nano33_ble_sense.png" width="50%" height="50%">

2. Das Kameramodul dient zur Aufnahme des Objekts.
<img src="images/camera_OV7675.png" width="50%" height="50%">

3. Zum Anzeigen der erkannten Müllart wird der M5Stick C PLUS verwendet. In ihm steckt ein ESP-32-PICO Mini. Für die Bluetoothkommunikation wird hierauf der Peripheriecode gespielt.
<img src="images/M5StickC_PLUS.png" width="50%" height="50%">

Der Microcontroller und das Kameramodul können über ein Board, das sogenannte *Tiny Machine Learning Shield*, verbunden werden.
<img src="images/hardware.png" width="50%" height="50%"> \
<img src="images/hardware_connected.png" width="50%" height="50%">

### 2.2 Edge Impulse
- beschreibung wofür
- registrierung
- projekt anlegen

### 2.3 Arduino IDE
- download
- alle libraries installieren
- wofür brauchen wir die ide im projekt

## 3 Umsetzung und Anleitung
In diesem Abschnitt wird die Müllerkennung umgesetzt.

### 3.1 Hardware vorbereiten
- flashen
- edge impulse cmd
- triber für kamera
- triber für m5stick

1. Firmware Nano 33 BLE Sense aktualisieren
* Es kann notwendig sein, ersteinmal die aktuelle Firmware des Nano zu aktualisieren und zu flashen. Dafür folgende zip-Datei herunterladen und entsprechendes Script für das eigene Betriebssystem öffnen: [Nano 33 BLE Sense board Edge Impulse firmware](https://cdn.edgeimpulse.com/firmware/arduino-nano-33-ble-sense.zip "Nano 33 BLE Sense firmware").

<img src="images/terminal_flash.png" width="50%" height="50%">

2. Verbinden zu Edge Impulse
* In cmd/Terminal folgenden Befehl eingeben, um den Nano mit Edge Impulse zu verbinden.
```
edge-impulse-daemon
```

3. Triber für Kameramodul/USB-Anschluss runterladen:
* [USB-Treiber von SiLabs](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers "USB-Treiber von SiLabs")

4. Triber/Library für M5StickC
* USB-Triber runterladen: [M5Stick USB-Triber](https://ftdichip.com/drivers/vcp-drivers/)
> Ggfs. muss die Sicherheitseinstellung unter macOS angepasst werden.
> * *System Preferences -> Security and Privacy -> General -> Allow downloadable apps from the following locations -> App Store and Approved Developer Options*

* Arduino IDE öffnen und auf *Arduino IDE -> Settings* gehen und folgenden Link in die Sektion *Additional boards manager URLs* einfügen: 
``https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json``

* Nun Boardtriber für den M5StickC Plus installieren. Dazu unter *Boards Manager* nach *M5Stack* suchen und vorgeschlagenes Board installieren. \
<img src="images/ai_m5_bm.png" width="50%" height="50%">

* Nun unter *Tools -> Board: ... -> M5Stack -> M5Stick-C-Plus* auswählen.

* Anschließend die Library installieren. Dazu unter *Library Manager* nach *M5StickCPlus* suchen und vorgeschlagene Library installieren. \
<img src="images/ai_m5_lib.png" width="50%" height="50%">

### 3.2 Daten
Für das Modell werden Daten in Form von Bildern benötigt. Das bedeutet, dass das Modell mit Fotos gefüttert werden muss. Dafür kann ganz einfach das eigene Handy mit dem Projekt in Edge Impulse verknüpft werden, sodass dann das Handy für die Aufnahme von Fotos gentuzt werden kann. Sobald das Handy mit mit dem Projekt verknüpft ist, werden die Fotos direkt in das Projekt geladen.

#### 3.2.1 Datensatz erstellen mit eigener Handykamera
1. Handy mit Edge Impulse verbinden

* Im Menü auf *Devices* gehen und auf den Button *Connect a new device* wählen. \
![AddDevice](images/ei_addDevice.png)

* Anschließend bei *Use your mobile phone* auf den Button *Show QR code* klicken. \
![ConnectPhone](images/ei_connectPhone.png)

* Nun mit dem eigenen Handy den QR-Code scannen. Im Browser sollte nun die Möglichkeit bestehen, Bilder aufzunehmen. Ggfs. müssen Berechtigungen für die Kamera freigegeben werden. Diese bestätigen, da ansonsten keine Fotos aufgenommen werden können. \
<img src="images/take_pictures.png" width="50%" height="50%">
<img src="images/ei_oniPhone.png" width="50%" height="50%">

* Das Label kann über den oberen *Label*-Button geändert werden.

#### 3.2.2 Labels und Klassifizierung
Für dieses Projekt wurden vier Labels gewählt:

1. *glas* für Glas
2. *kunststoff* für Kunststoff
3. *restmuell* für Restmüll
4. *pappe* für Pappe

Desweiteren wurde noch testweise das Label *noise* hinzugefügt, um bspw. Umgebungs- und Hintergrundrauschen auszufiltern. Dies erweiste sich jedoch als nicht relevant bzw. hatte keinen sichtbaren Einfluss auf die Genauigkeit der Daten und wird deshalb hier nicht weiter erwähnt.

#### 3.2.3 Datensatz und verwendete Objekte
In Edge Impulse können nun unter dem Menüpunkt *Data acquisition* alle aufgenommen Bilder eingesehen werden und ggfs. editiert werden, wenn bspw. das Label falsch gesetzt wurde. Auch können hier Bilder wieder gelöscht werden.

<img src="images/ei_da.png" width="50%" height="50%">

Der Datensatz besteht vollständig aus eigenständig aufgenommen Daten, d.h. es wurde kein fremder Datensatz (hinzu)gewählt. Der Train/Test-Split wurde auf 80/20 festgesetzt. Insgesamt wurden 1.047 Trainigsdaten und 251 Testdaten erstellt. Von diesen 1.047 Trainingsdaten sind 278 Aufnahmen von Glas, 242 Aufnahmen von Kunststoff, 267 Aufnahmen von Pappe und 242 Aufnahmen von Restmüll. Für Glas wurde ein durchsichtiges, farbloses Konservenglas vor unterschiedlichem Hintergrund und in unterschiedlichen Winkeln aufgenommen. Für Kunststoff eine Süßigkeiten-Plastik-Tüte, für  Restmüll eine Banane und für Pappe ein zusammengeknülltes Papierstück.

### 3.3 Modell trainieren
Um das Modell zu trainieren, nun im Seitenmenü auf *Impulse design* gehen.

* Create Impulse: Impuls anlegen
<img src="images/ei_createImp.png" width="50%" height="50%">

* Image: Bildparameter einstellen \
<img src="images/ei_paramRgb.png" width="50%" height="50%"> \

* Generate Features klicken \
<img src="images/ei_generateF.png" width="50%" height="50%">

* Transfer learning: Trainingsmodell wählen \
<img src="images/ei_model.png" width="50%" height="50%"> \
Es wird das Modell **MobileNetV1 96x96 0.25** gewählt. Dieses ist ein schmales Modell zur Klassifizierung von Daten.

* Start training: Modell trainieren 
<img src="images/ei_accuracy.png" width="50%" height="50%"> \
Nachdem das Modell trainiert wurde, wird die Performence und ein Datenexplorer im Tranining Output angezeigt. Das hier trainierte Modell hat nun eine Genauigkeit von 90,5 Prozent.

* Deployment: Modell exportieren
- *Arduino library* wählen
- Auf *Build* klicken und zip-Datei exportieren

### 3.4 Code in Arduino IDE (besseren Titel wählen)

#### 3.4.1 Müllerkennung
- import modell zip als library
- über examples code für kamera öffnen
- auf nano spielen
- in serial monitor ausgabe anzeigen

<img src="images/detect_glas.png" width="50%" height="50%">
<img src="images/output_detect_glas.png" width="50%" height="50%">

<img src="images/detect_plastic.png" width="50%" height="50%">
<img src="images/output_detect_plastic.png" width="50%" height="50%">

<img src="images/detect_rest.png" width="50%" height="50%">
<img src="images/output_detect_rest.png" width="50%" height="50%">

<img src="images/detect_paper.png" width="50%" height="50%">
<img src="images/output_detect_paper.png" width="50%" height="50%">

#### 3.4.2 Bluetooth auf Nano 33

#### 3.4.3 Bluetooth auf M5Stick

### 3.5 Ausgabe auf M5Stick

## 4 Potenziale und Ausblick

Es gibt unterschiedlichste Bereiche, wo der Prototyp perspektivisch eingesetzt werden kann. Zum einen wäre es möglich die Waste Detection einzusetzen, um manuelle Nacharbeit von Fließarbeitern einzusparen. Zum anderen, könnte  ein Anwendungsfall sein, dass Hinweise oder Alarme bei falscher Mülltrennung gegeben werden, wenn der Müll in die falsche Mülltonne geschmissen wurde. Dies könnte auch weitergeführt werden durch das Einbeziehen der Gamification. Gamification ist die Übertragung von spieltypischen Elementen und Vorgängen in spielfremde Zusammenhänge, wodurch auch die Motivation erhöht werden könnte mehr auf die Mülltrennung zu achten. Denn die Idee wäre es, bei jeder richtigen Mülltrennung Punkte zu vergeben. In einem Umfeld wie der Deutschen Bahn wäre sowas sicherlich, in Anbretracht der Nachhaltigkeit, ein attraktives Projekt. Des Weiteren könnte der Prototyp auch Kindern die Mülltrennung beibringen oder auch blinden Menschen sagen, wo sie ihren Müll wegschmeißen sollen.
Zudem wäre es möglich den Prototypen einzusetzen, um Kindern die Mülltrennung beizubringen sowie blinden Mensch die Mülltrennung zu erleichtern. 
Der Prototyp lässt sich natürlich auch um weitere Funktionalitäten ausweiten, wie beispielsweise durch einen Feuchtigkeitssensor. Beispielsweise könnte man somit die Feuchtigkeit im Biomüll messen, um so den Grad der Verwesung herauszufinden. Somit weiß man wann der Biomüll weggeworfen werden muss. 
In einer Bachelorarbeit "Household Recycle Sorting Bin System Design" von der Bangor Universität wird aufgezeigt wie mittels von Tonsensorik die unterschiedlichen Müllarten, wie Kunststoff-, Glas-, Metall- und Papiermüll, erkannt wurde. Dabei wurde der Müll auf einen Sensor fallen gelassen und durch den Ton konnte man die Müllart einordnen. Das Projekt wurde auch mit der Arduino IDE und Edge Impulse realisiert.(3) Um beispielsweise den unangenehmen Müllgeruch zu vermeidem könnte man zudem umsetzen, dass in Echtzeit das Volumen und der Geruch, also die biologische Abbaubarkeit des darin enthaltenen Abfalls, rückverfolgt wird und den Nutzer benachrichtigt, sobald der festgelegte Schwellenwert für das Volumen überschritten wird oder ein Geruch sich ausbreitet. Da könnte ein Ultraschall-Abstandssensor HRSO4 und ein Halbleiter-Gassensoren der MQ-Serie MQ4 und MQ135, die an dem Mikrocontroller angeschlossen werden und zur Füllstands- und biologischen Abbaubarkeitsmessung eingesetzt werden.(4)
Es gibt es unterschiedlichste Möglichkeiten den Prototypen auszuweiten und einzusetzen, da der Mehrwert in allen Bereichen hoch ist. Denn durch Mülltrennung kann auch die Wiederverwendung von recycelbaren Materialien gefördert und der Anteil des in Deponien entsorgten Abfalls reduziert werden.


NOCH NOTIZEN:
Dadurch wird die Wiederverwendung von recycelbaren Materialien gefördert und der Anteil des in Deponien entsorgten Abfalls reduziert werden.

## 5 Trouble shooting

## Literaturverzechnis

1) Alam, P. and Ahmade, K., 2013. Impact of solid waste on health and the environment. International Journal of Sustainable Development and Green Economics (IJSDGE), 2(1), pp.165-168.

2) de Souza Melaré, A.V., González, S.M., Faceli, K. and Casadei, V., 2017. Technologies and decision support systems to aid solid-waste management: a systematic review. Waste management, 59, pp.567-584.
3) Schoon, L. 2021. Household Recycle Sorting Bin System Design. Bangor Unversity. pp.6-7.
4) Mbom, H., Abukabar, R., Abolade, O., 2022. Design and implementation of an IoT based smart waste bin for fill level and biodegradability monitoring. Department of Systems Engineering, University of Lagos, Lagos, Nigeria.
