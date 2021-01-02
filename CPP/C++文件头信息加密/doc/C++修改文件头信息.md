## 目的

为了保护隐私，对敏感级别稍微低一些的文件，存储到网盘等外部时，需要考虑文件加密，使用压缩包的方式去搞，不仅占用加密过程时间长，占用空间大，以及接下来的解密过程也是耗时的操作，为此研究了文件头信息。每个文件存在都是以二进制的形式存在，每个类型的文件头信息都是标准化的，让计算机无法识别我们的文件，利用此特性修改文件头信息，达到加密文件的信息。



## 分析

计算中读取文件并不是以结尾后缀来识别文件类型的，更多的是读取文件头信息来识别该文件的类型，如下是常见的文件头信息

| 文件格式                   | 文件头                       |
| -------------------------- | ---------------------------- |
| JPEG (jpg)                 | FFD8FF                       |
| PNG (png)                  | 89504E47                     |
| GIF (gif)                  | 47494638                     |
| TIFF (tif)                 | 49492A00                     |
| Windows Bitmap (bmp)       | 424D                         |
| CAD (dwg)                  | 41433130                     |
| Adobe Photoshop (psd)      | 38425053                     |
| Rich Text Format (rtf)     | 7B5C727466                   |
| XML (xml)                  | 3C3F786D6C                   |
| HTML (html)                | 68746D6C3E                   |
| Email (eml)                | 44656C69766572792D646174653A |
| Outlook Express (dbx)      | CFAD12FEC5FD746F             |
| Outlook (pst)              | 2142444E                     |
| MS Word/Excel (xls.or.doc) | D0CF11E0                     |
| MS Access (mdb)            | 5374616E64617264204A         |
| WordPerfect (wpd)          | FF575043                     |
| Postscript (eps.or.ps)     | 252150532D41646F6265         |
| Adobe Acrobat (pdf)        | 255044462D312E               |
| Quicken (qdf)              | AC9EBD8F                     |
| Windows Password (pwl)     | E3828596                     |
| ZIP Archive (zip)          | 504B0304                     |
| RAR Archive (rar)          | 52617221                     |
| Wave (wav)                 | 57415645                     |
| AVI (avi)                  | 41564920                     |
| Real Audio (ram)           | 2E7261FD                     |
| Real Media (rm)            | 2E524D46                     |
| MPEG (mpg)                 | 000001BA                     |
| MPEG (mpg)                 | 000001B3                     |
| Quicktime (mov)            | 6D6F6F76                     |
| Windows Media (asf)        | 3026B2758E66CF11             |
| MIDI (mid)                 | 4D546864                     |



以下UltraEdit 打开PNG图片的16进制数据，可以看到文件头信息是 89504E470D0A

一般4个字节的数据就能匹配出来当前的文件类型，可能有些类型的文件需要读取更多的数据来区分，8个字节的数据也差不多足够了。

<img src="C++%E4%BF%AE%E6%94%B9%E6%96%87%E4%BB%B6%E5%A4%B4%E4%BF%A1%E6%81%AF.assets/image-20210102201725751.png" alt="image-20210102201725751"  />



## 设计

分析清楚了文件头信息的原理，按照加密、解密的整理功能设计如下

加密过程

- 解析文件头信息
- 重写文件头（按照自定义头文件格式)
- 文件名加密、文件后缀重命名
- 记录文件名原始信息 到MapInfo.txt

解密过程:

- 加密文件判断
- 文件头信息解析
- 解密文件头信息
- 恢复文件名及后缀



![C文件头信息加密](C++%E4%BF%AE%E6%94%B9%E6%96%87%E4%BB%B6%E5%A4%B4%E4%BF%A1%E6%81%AF.assets/C%E6%96%87%E4%BB%B6%E5%A4%B4%E4%BF%A1%E6%81%AF%E5%8A%A0%E5%AF%86-1609598541238.svg)