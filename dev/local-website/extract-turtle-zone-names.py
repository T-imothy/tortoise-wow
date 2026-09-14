from pathlib import Path
import struct,json
data=Path(r'C:\Users\root\Desktop\WorkFolder\turtle\data\dbc\AreaTable.dbc').read_bytes()
magic,rows,fields,size,strings=struct.unpack_from('<4s4I',data)
assert magic==b'WDBC' and fields==25 and size==fields*4
base=20+rows*size
assert base+strings==len(data)
names={}
for i in range(rows):
    record=struct.unpack_from('<25I',data,20+i*size)
    offset=record[11]
    assert offset<strings
    name=data[base+offset:data.index(b'\0',base+offset)].decode('utf-8')
    if name:names[str(record[0])]=name
assert names['1']=='Dun Morogh'
Path(__file__).with_name('turtle-zone-names.json').write_text(json.dumps(names,ensure_ascii=False),encoding='utf-8')
print(f'Extracted {len(names)} area names from the current Turtle DBC, including custom zones.')
