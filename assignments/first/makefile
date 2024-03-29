CFLAGS = -g -std=c++11 -I. 
COMPILE = g++ $(CFLAGS) -c
LINK = g++ $(CFLAGS)
LIBS = -lGL -lGLU -lglut -lmpfr

acp.o:	acp.cc acp.h
	$(COMPILE) acp.cc

object.o: object.cc object.h acp.h
	$(COMPILE) object.cc

point.o: point.C point.h object.h pv.h acp.h
	$(COMPILE) point.C

warmup: warmup.C point.o object.o acp.o
	$(LINK) warmup.C point.o object.o acp.o $(LIBS) -o warmup

plot.o: plot.C plot.h point.h pv.h acp.h
	$(COMPILE) plot.C

hull.o: hull.C hull.h object.h pv.h acp.h
	$(COMPILE) hull.C

hullplot.o : hullplot.C plot.h hull.h point.h pv.h acp.h
	$(COMPILE) hullplot.C

hull	: hullplot.o plot.o hull.o point.o object.o acp.o
	$(LINK) hullplot.o plot.o hull.o point.o object.o acp.o \
	$(LIBS) -o hull

permute.o: permute.C permute.h
	$(COMPILE) permute.C

circle.o: circle.C circle.h point.h object.h pv.h acp.h
	$(COMPILE) circle.C

mindisk.o : mindisk.C mindisk.h circle.h point.h object.h pv.h acp.h
	$(COMPILE) mindisk.C

diskplot.o : diskplot.C plot.h mindisk.h circle.h point.h pv.h acp.h
	$(COMPILE) diskplot.C

mindisk	: diskplot.o plot.o mindisk.o permute.o circle.o point.o object.o acp.o
	$(LINK) diskplot.o plot.o mindisk.o permute.o circle.o point.o object.o acp.o \
	$(LIBS) -o mindisk

arrange.o: arrange.C arrange.h circle.h point.h object.h pv.h acp.h
	$(COMPILE) arrange.C

aplot.o	: aplot.C aplot.h arrange.h point.h pv.h acp.h
	$(COMPILE) aplot.C

setplot.o : setplot.C aplot.h plot.h arrange.h point.h pv.h acp.h
	$(COMPILE) setplot.C

setop	: setplot.o aplot.o plot.o arrange.o point.o object.o acp.o
	$(LINK) setplot.o aplot.o plot.o arrange.o point.o object.o acp.o \
	$(LIBS) -o setop

carrange.o : carrange.C carrange.h circle.h point.h object.h pv.h acp.h
	$(COMPILE) carrange.C

csetplot.o : csetplot.C plot.h carrange.h point.h pv.h acp.h
	$(COMPILE) csetplot.C

csetop	: csetplot.o plot.o carrange.o circle.o point.o object.o acp.o
	$(LINK) csetplot.o plot.o carrange.o circle.o point.o object.o acp.o \
	$(LIBS) -o csetop

mink.o	: mink.C mink.h arrange.h point.h object.h pv.h acp.h
	$(COMPILE) mink.C

minkplot.o : minkplot.C aplot.h plot.h mink.h arrange.h point.h pv.h acp.h
	$(COMPILE) minkplot.C

mink	: minkplot.o aplot.o plot.o mink.o arrange.o point.o object.o acp.o
	$(LINK) minkplot.o aplot.o plot.o mink.o arrange.o point.o object.o acp.o \
	$(LIBS) -o mink

triangulate.o :	triangulate.C triangulate.h arrange.h point.h object.h pv.h acp.h
	$(COMPILE) triangulate.C

triplot.o : triplot.C aplot.h point.h pv.h acp.h
	$(COMPILE) triplot.C

triangulate :	triplot.o aplot.o plot.o triangulate.o arrange.o point.o object.o acp.o
	$(LINK)	triplot.o aplot.o plot.o triangulate.o arrange.o point.o object.o acp.o \
	$(LIBS) -o triangulate

tmap.o	: tmap.C tmap.h arrange.h point.h object.h pv.h acp.h
	$(COMPILE) tmap.C

tmapplot.o : tmapplot.C tmapplot.h aplot.h plot.h tmap.h arrange.h point.h pv.h acp.h
	$(COMPILE) tmapplot.C

tmap : tmapplot.o aplot.o plot.o tmap.o permute.o arrange.o point.o object.o acp.o
	$(LINK) tmapplot.o aplot.o plot.o tmap.o permute.o arrange.o point.o object.o acp.o \
	$(LIBS) -o tmap

voronoi.o : voronoi.C voronoi.h point.h object.h pv.h acp.h
	$(COMPILE) voronoi.C

vorplot.o : vorplot.C aplot.h plot.h voronoi.h arrange.h circle.h point.h pv.h acp.h
	$(COMPILE) vorplot.C

voronoi : vorplot.o aplot.o plot.o voronoi.o arrange.o circle.o point.o object.o acp.o
	$(LINK) vorplot.o aplot.o plot.o voronoi.o arrange.o circle.o point.o object.o acp.o \
	$(LIBS) -o voronoi

delaunay.o : delaunay.C delaunay.h arrange.h circle.h permute.h point.h \
	object.h pv.h acp.h
	$(COMPILE) delaunay.C

delplot.o : delplot.C aplot.h plot.h delaunay.h point.h pv.h acp.h
	$(COMPILE) delplot.C

delaunay : delplot.o aplot.o plot.o delaunay.o permute.o arrange.o circle.o point.o \
	object.o acp.o
	$(LINK) delplot.o aplot.o plot.o delaunay.o permute.o arrange.o circle.o \
	point.o object.o acp.o \
	$(LIBS) -o delaunay

hull3.o	: hull3.C hull3.h object.h pv.h acp.h permute.h
	$(COMPILE) hull3.C

hull3	: hull3.o object.o acp.o permute.o
	$(LINK) hull3.o object.o acp.o permute.o -lmpfr -o hull3

vis.o	: vis.C vis.h arrange.h point.h object.h pv.h acp.h
	$(COMPILE) vis.C

visplot.o : visplot.C plot.h vis.h arrange.h point.h pv.h acp.h
	$(COMPILE) visplot.C

vis	: visplot.o plot.o vis.o arrange.o point.o object.o acp.o
	$(LINK) visplot.o plot.o vis.o arrange.o point.o object.o acp.o \
	$(LIBS) -o vis

clean : 
	rm -f *.o *~ hull mindisk setop csetop mink triangulate tmap voronoi \
	delaunay hull3 vis
